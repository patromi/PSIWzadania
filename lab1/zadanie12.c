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
    char ascii[127] = {0}; 

    int suma = 0;
    int fd = open(argv[1], O_RDWR);
    if (fd == -1) {
        perror("error");
        return 1;
    }

    int rd;
    while ((rd = read(fd, buf, MAX)) > 0) {
        for (int i = 0; i < rd; i++) {
            if (buf[i] != '\n' && buf[i] != ' ' && isascii(buf[i])) {
                ascii[(int)buf[i]] += 1;
                suma += 1;
            }
        }
    }

    int max = -1;
    int word = 0;
    for (int i = 65; i < 123; i++) {
        if (ascii[i] > max) {
            max = ascii[i];
            word = i;
        }
    }

    if (suma > 0) {
        double percentage = (double)max / suma * 100;
        printf("The most common letter is '%c', it appear in %.2f%% time in whole file \n", word, percentage);
    }

    close(fd);
    return 0;
}
