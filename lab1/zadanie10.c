#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#define MAX 512

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Za mało argumentów\n");
        return 1;
    }


    char buf[MAX];
    int fd = open(argv[argc-1], O_WRONLY | O_TRUNC |O_APPEND);
    if (fd == -1) {
        perror("error");
        return 1;
    }

    for (int i = 1; i < argc - 1; i++) {
        int fd1 = open(argv[i], O_RDONLY);
        if (fd1 == -1) {
            perror("error");
            close(fd);
            return 1;
        }

        int rd;
        while ((rd = read(fd1, buf, MAX)) > 0) {
            write(fd, buf, rd);
            for (int d = 0; d < rd; d++) {
                printf("%c", buf[d]);
            }
        }

        close(fd1);
        memset(buf, 0, MAX); 
    }

    close(fd);
    return 0;
}
