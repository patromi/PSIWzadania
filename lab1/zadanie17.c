#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#define MAX 512

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Za mało argumentów\n");
        return 1;
    }
    int fd = open(argv[1],O_RDONLY);
    int fd2 = open(argv[2],O_RDONLY);
    if (fd==-1||fd2==-1){
        perror("Error");
        return 1;
    }
    char buf[MAX];
    char buf2[MAX];
    int start;
    int rd;
    int rd2;
    int is_same=1;
    while ((rd = read(fd, buf, MAX)) > 0 && ((rd2 = read(fd, buf2, MAX))> 0)) {

        for (int j = 0; j < rd; j++) {
            if (buf[j] != buf2[j]){
                is_same=0;
            }
        }
    }

    if (is_same==1){
        printf("Pliki są identyczne");
    }
    return 0;
}
