#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include "signal.h"
#include "stdlib.h"

void sig_alaram(int signo) {
}

int main(int argc, char *argv[]) {


    void (*f)();
    f = signal(SIGALRM, sig_alaram);
    printf("start\n");

    while (1) {
        printf("'I'm working ");
        printf("I'm sleep for 5 sec");
        alarm(5);
        pause();
    }



    return 0;
}
