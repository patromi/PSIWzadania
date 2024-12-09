#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char *argv[]) {

    char buf[128];
    int fd = read(0, buf, 128);
    int n = atoi(buf);
    int i;
    unlink("rura");
    mkfifo("rura", 0666);
    int d = fork();

    if (d == 0){
        mkfifo("client", 0666);
        int fd = open("rura", O_RDONLY);
        char buf[128];
        write(1, "ls", 2);
    }
    else {

        for (i = 0; i < n; i++) {
            if (fork() == 0) {


            }
        }
    }

    return 0;
}
