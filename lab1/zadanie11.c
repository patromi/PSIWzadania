#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX 512

int main(int argc, char *argv[]) {
    int fd;

    if (argc < 2) {
        printf("Enter words (ctrl+d to end):");
        fd=0;

    } else {
        fd = open(argv[1], O_RDONLY);
        if (fd == -1) {
            perror("error");
            return 1;
        }
    }

    char buf[MAX];
    int word_count = 0;
    int rd;

    while ((rd = read(fd, buf, MAX)) > 0) {
        for (int i = 0; i < rd; i++) {
            if (buf[i] == ' ' || buf[i] == '\n') {
                word_count++;
            }
        }
    }


    printf("Liczba słów w pliku: %d\n", word_count);

    close(fd);
    return 0;
}
