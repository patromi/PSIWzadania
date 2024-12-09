#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h>

#define MAX 512
int main(int argc, char *argv[]) {

    if (argc < 2){
        printf("Za mało argumentów\n");
        return 1;
    }
    int fd = open(argv[1], O_WRONLY | O_TRUNC | O_APPEND);

    int proc1 = fork();
    wait(NULL);
    if (proc1 == 0) {

    }

    return 0;}