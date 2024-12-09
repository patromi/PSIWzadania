#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
int main(int argc, char *argv[]) {

    int proc1 = fork();
    int proc2 = fork();

    printf("PID: %d, PPID: %d, proc1: %d, proc2: %d\n", getpid(), getppid(), proc1, proc2);

    return 0;
}
