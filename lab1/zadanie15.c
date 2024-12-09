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

    char *looking = argv[1];
    char buf[MAX];
    unsigned long size = strlen(looking);

    for (int i = 2; i < argc; i++) {

    int fd = open(argv[i], O_RDONLY);
    if (fd == -1) {
        perror("error");
        return 1;
    }

    int element=0;
    int rd;
    int lines=1;
    while ((rd = read(fd, buf, MAX)) > 0) {

        for (int j = 0; j < rd ; j++) {
            if (buf[j] == looking[element]){
                element++;
            }
            else{
                element=0;
            }
            if (buf[j]== '\n'){
                lines++;
            }
            if (element == size){
                printf("Znaleziono podany tekst w pliku %s zaczyna sie na %d bajcie i konczy na %d w lini %d\n",argv[i],j-element+2,j+2,lines);
            }
        }
        }
        close(fd);

    }





    return 0;
}
