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
    unlink("rura");
    unlink("client");
    int d =mkfifo("rura", 0666);
    int serwer = fork();
    if (serwer != 0) {
        int client = fork();
        if (client == 0) {
            printf("Client\n");

            int serwer_fd = open("rura", O_WRONLY);
            const char *message = "client";
            if (write(serwer_fd, message, strlen(message) + 1) == -1) {
                perror("write to serwer");
            }
            close(serwer_fd);


            int client_fd = open("client", O_RDONLY);
            char buf[128];
            read(client_fd, buf,  128);
            printf("Client odebrał: %s\n", buf);

            close(client_fd);
        } else {
            mkfifo("client", 0666);
            int serwer_fd = open("rura", O_RDONLY);

            char buf[128];
            read(serwer_fd, buf, sizeof(buf) - 1);
            printf("Serwer odebrał: %s\n", buf);


            int client_fd = open(buf, O_WRONLY);
            printf("%d\n", client_fd);

            dup2(client_fd, 1);
            wait(NULL);
            execlp("ls", "ls", "-la" , buf, NULL);

            return 1;
        }
    }
    else{

    }

    return 0;
}
