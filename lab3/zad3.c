#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include "signal.h"
#include "stdlib.h"




int main(int argc, char *argv[]) {

    if (argc <2){
        printf("You have to pass seconds as an argument\n");
        return 1;
    }

    alarm(atoi(argv[1]));

    while (1){
        printf("I'm working!!");
    }

    return 0;
}
