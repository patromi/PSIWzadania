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
            int f3 = fork();

            if (f3 == 0)
            {
                close(fd[0]);
                write(fd[1], "Hello ", 6);
                close(fd[1]);

            }
            else {
                close(fd[0]);
                write(fd[1], "Hello2 ", 7);
                close(fd[1]);
            }
        } else {
            char buf[4];
            wait(NULL);
            close(fd[1]);
            read(fd[0], buf, 12);
            printf("%s\n", buf);
            close(fd[0]);

        }
    } else{
        wait(NULL);
    }

    return 0;
}
