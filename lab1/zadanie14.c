#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAX 512

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Za mało argumentów\n");
        return 1;
    }
    srand(time(NULL));   
    char buf[MAX];

    int suma = 0;
    int fd = open(argv[1], O_RDWR);
    if (fd == -1) {
        perror("error");
        return 1;
    }
    int start=0;
    int rd;
    while ((rd = read(fd, buf, MAX)) > 0) {
        for (int i = 0; i < rd; i++) {

            if (buf[i]=='\n'){
                for (int d = start; d < i; d++) {
                    int r = start + rand() % (d - start + 1);
                    char temp = buf[d];  
                    buf[d] = buf[r];     
                    buf[r] = temp;       
                }
                start = i;
            }
            }
        for(int j=0;j<rd;j++){
            printf("%c",buf[j]);
        }
        }
    close(fd);
    return 0;
}
