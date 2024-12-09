#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#define MAX 512
int main(int argc, char *argv[]) {

    if (argc <2) {
    printf( " Za malo argumentow  ");
    return 1;
    } 
    char buf[MAX];
    int fd = open(argv[1],O_RDWR);
    if (fd==-1){
        return 1;
    }

    int rd;
    int licznik = 0;
    int seek2 = lseek(fd,-MAX,SEEK_END);
    while(rd = read(fd,buf,MAX)){
        printf("\n10 ost znakoów\n");
       
        for (int i = rd-10; i < rd; i++)
            printf("%c",buf[i]);
        {
        }
        printf("\n10 słów ost\n\n");
        for (int i = rd - 1; i >= 0; i--) {
            if (buf[i] == ' ' || buf[i] == '\n') {
                licznik++;

                if (licznik == 10) {
                    for (int d=i-1; d < rd; d++){
                        printf("%c",buf[d]);
                    }

                    return 0;
                }
            }
        }
        printf("10 ost lin");

        for (int i = rd - 1; i >= 0; i--) {
            if (buf[i] == '\n') {
                licznik++;

                if (licznik == 10) {
                    for (int d=i-1; d < rd; d++){
                        printf("%c",buf[d]);
                    }

                    return 0;
                }
            }
        }

        int seek = lseek(fd,-rd*2,SEEK_CUR);
    }
    return 0;
}
