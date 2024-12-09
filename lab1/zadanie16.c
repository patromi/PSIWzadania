#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX 512

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Za mało argumentów\n");
        return 1;
    }

    int akapit = atoi(argv[1]) + 1;
    char buf[MAX];
    char buf2[MAX];

    for (int i = 2; i < argc; i++) {
        int fd = open(argv[i], O_RDWR);
        if (fd == -1) {
            perror("error");
            return 1;
        }
        int new_line;
        int counter = 0;
        int rd;

        int fd_temp = open("temp.tmp", O_CREAT | O_RDWR | O_TRUNC, 0644);
        if (fd_temp == -1) {
            perror("error");
            close(fd);
            return 1;
        }

        while ((rd = read(fd, buf, MAX)) > 0) {
            for (int j = 0; j < rd; j++) {
                if (counter >= akapit && (buf[j]==' ' || buf[j] == '\n' || buf[j]=='\t')) {
                    write(fd_temp, "\n", 1);
                    counter = 0;
                    new_line=1;
                } else {
                    counter++;
                }
                if (new_line==1){new_line=0;continue;}
                if (buf[j]=='\n'){
                    write(fd_temp, " ", 1);
                    continue;
                }
                if (write(fd_temp, &buf[j], 1) == -1) {
                    perror("write error");
                    close(fd);
                    close(fd_temp);
                    return 1;
                }
            }
        }
        close(fd_temp);
        fd_temp = open("temp.tmp",O_RDONLY);
        lseek(fd,0,SEEK_SET);
        while ((rd = read(fd_temp, buf2, MAX)) > 0) {

            write(fd,buf2,rd);
        }
        close(fd);
    }

    return 0;
}
