#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
    int proc1 = fork();
    int proc2 = fork();
    int proc3 = fork();
    if (proc1 == 0) {
        exit(1);
    }
    if (proc2 == 0) {
        exit(1);
    }
    if (proc3 == 0) {
        exit(1);
    }

    printf("PID: %d, PPID: %d, proc1: %d, proc2: %d, proc3: %d\n", getpid(), getppid(), proc1, proc2, proc3);
    execlp("ps","ps","aux",NULL);
    return 0;}