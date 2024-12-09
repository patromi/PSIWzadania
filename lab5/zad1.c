#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include "signal.h"
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {

    int fd[2];

    mkfifo("rura", 0666);

    int f1 = fork();
    if (f1 == 0) {
        int desk = open("rura", O_WRONLY);
        write(desk, "Hello", 5);
        close(desk);

    }
    else {
    }
    int desk = open("rura", O_RDONLY);
    char buf[512];
    read(desk, buf, 512);
    printf("%s\n", buf);
    execvp("unlink rura", argv);
    close(desk);

    return 0;
}