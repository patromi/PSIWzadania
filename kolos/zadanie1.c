#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include "signal.h"


void sig_int(int signo) {
    printf("SIGINT\n");
}

void sig_stop(int signo) {
    printf("SIGTSP\n");
}

void sig_quit(int signo) {
    printf("SIGQUIT\n");
}

int main(int argc, char *argv[]) {

    signal(SIGINT, sig_int);
    signal(SIGTSTP, sig_stop);
    signal(SIGQUIT, sig_quit);
    while(1) {
        pause(); // Czeka na sygnał
    }


    return 0;
}
