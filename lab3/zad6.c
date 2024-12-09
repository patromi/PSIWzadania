#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include "signal.h"
#include "stdlib.h"
#include "time.h"
#include "sys/wait.h"

int main(int argc, char *argv[]) {

    int p1 = fork();
    int p2 = fork();
    int p3 = fork();
    srand(time(NULL));
    int value = rand();

    if (p1 == 0) {
        sleep(value % 10);
        exit(0);
    }
    if (p2 == 0) {
        sleep(value % 10);
        exit(0);

    }
    if (p3 == 0) {
        sleep(value % 10);
        exit(0);
    }

    wait(NULL);
    if (p1 != 0) {
        kill(p1, SIGTERM);

    }
    if (p2 != 0) {
        kill(p2, SIGTERM);

    }

    if (p3 != 0) {
        kill(p3, SIGTERM);

    }


    return 0;
}
