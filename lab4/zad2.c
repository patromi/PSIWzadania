#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include "signal.h"
#include <sys/wait.h>



int main(int argc, char *argv[]) {

    int fd[2];
    int f1 = fork();
    if (f1 == 0 ) {
        int rura = pipe(fd);
        int f2 = fork();


        if (f2 == 0 ) {

            char buf[4];
            close(fd[1]);
            read(fd[0], buf, 5);
            printf("%s\n", buf);
            close(fd[0]);
        } else {
            close(fd[0]);
            write(fd[1], "Hello", 5);
            close(fd[1]);
            wait(NULL);
        }
    } else{
        wait(NULL);
    }

    return 0;
}
