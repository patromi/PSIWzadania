#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    mkfifo("rura", 0666);
    int f1 = fork();
    if (f1 == 0) {
        int f2 = fork();
        if (f2 == 0) {
            int f3 = fork();
            if (f3==0){


            int desk = open("rura", O_WRONLY);
            dup2(desk, 1);
            execlp("ps" ,"-ef", 0);
            close(desk);}
        else {
                int desk = open("rura", O_RDONLY);
                dup2(desk, 0);
                close(desk);
                execlp("tr","-s","' '", ":", NULL);
                wait(NULL);

        }

        }
    else{
            int desk = open("rura", O_RDONLY);
            dup2(desk, 0);
            close(desk);
            execlp("cut","-d:","-f1", NULL);
            wait(NULL);
    }

    } else {
        int desk = open("rura", O_RDONLY);
        dup2(desk, 0);
        close(desk);
        execlp("sort", NULL);
        wait(NULL);
    }
    return 0;
}