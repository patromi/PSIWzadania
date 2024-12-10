#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include "signal.h"
#include "sys/wait.h"
//Napisz program który tworzy trzy procesy, z których dwa zapisują do potoku, a
//        trzeci odczytuje z niego i drukuje otrzymane komunikaty

int main(int argc, char *argv[]) {

    int fd[2];
    int rura = pipe(fd);

    if (fork() == 0 ){

        if (fork()==0){
            close(fd[0]);
            write(fd[1],"Hello",6);
            close(fd[1]);
        }
        else{
            close(fd[0]);
            write(fd[1],"World ",6);
            close(fd[1]);
        }
    }

    wait(NULL);
    close(fd[1]);
    char buf[20];
    read(fd[0],buf,20);
    printf("%s",buf);
    close(fd[1]);

    return 0;
}
