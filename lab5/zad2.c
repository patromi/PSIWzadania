#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    mkfifo("rura", 0666);
    int f1 = fork();
    if (f1 == 0) {
        int desk = open("rura", O_WRONLY);
        dup2(desk, 1);
        char *args[] = {"ls", NULL};
        execvp("ls", args);
        close(desk);
    } else {
        int desk = open("rura", O_RDONLY);
        dup2(desk, 0);
        close(desk);
        execlp("wc", NULL);
        wait(NULL);
    }
    return 0;
}