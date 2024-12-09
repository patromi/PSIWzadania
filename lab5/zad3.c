#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

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
            int client_fd = open("client", O_RDONLY);
            const char *message = "client";
            if (write(serwer_fd, message, strlen(message) + 1) == -1) {
                perror("write to serwer");
            }
            close(serwer_fd);
            close(client_fd);
            return 0;
        } else {
            mkfifo("client", 0666);
            int serwer_fd = open("rura", O_RDONLY);
            int client_fd = open("client", O_WRONLY);

            char buf[128];
            read(serwer_fd, buf, sizeof(buf) - 1);
            printf("Serwer odebrał: %s\n", buf);
            execlp("ls", "ls", "-la" , buf, NULL);

            return 1;
        }
    }
    else{

    }

    return 0;
}
