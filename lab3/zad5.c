#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include "signal.h"
#include "stdlib.h"


int main(int argc, char *argv[]) {

    signal(SIGCLD, SIG_IGN);

    int p1 = fork();
    int p2 = fork();
    while(1){
        if (p1 == 0) {
            printf("Child PID: %d\n", getpid());
            exit(0);
        }
        if (p2 == 0) {
            printf("Child PID: %d\n", getpid());
            exit(0);
        }
    }


    if (p1 != 0) {
        printf("Parent PID: %d\n", getpid());
        void (*f)();
    }
    if (p1 == 0) {
        printf("Child PID: %d\n", getpid());
        printf("Parent PID: %d\n", getppid());
        exit(0);
    }

    printf("PID: %d\n", getpid());


    return 0;
}
