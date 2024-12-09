#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include "signal.h"
#include "stdlib.h"
#include "time.h"
#include "sys/wait.h"

int main(int argc, char *argv[]) {

    int ls = fork();
    int ps = fork();

    printf("PID: %d, PPID: %d, ls: %d, ps: %d\n", getpid(), getppid(), ls, ps);

    return 0;
}
