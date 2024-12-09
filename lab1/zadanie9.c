#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <ctype.h>
#define MAX 512

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Za mało argumentów\n");
        return 1;
    }

    char buf[MAX];
    int zm = 0; 
    int fd = open(argv[1], O_RDWR);
    if (fd == -1) {
        perror("error");
        return 1;
    }

    int rd;
    while ((rd = read(fd, buf, MAX)) > 0) {
        for (int i = 0; i < rd; i++) {
            if (isascii(buf[i])) {
            if (buf[i] >= 97 && buf[i] <=122){
                buf[i] = buf[i] - 25;
            }


            }
        }
        for (int i = 0; i < rd; i++) {
            printf("%c",buf[i]);
        }
        
    }

    if (rd == -1) {
        perror("error");
        close(fd);
        return 1;
    }

    close(fd);
    return 0;
}
