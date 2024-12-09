#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#define MAX 512
int main(int argc, char *argv[]) {

    if (argc <2) {
    printf( " Za malo argumentow  ");
} 
    char buf[MAX];
    int fd = open(argv[1],O_RDWR);
    if (fd==-1){
        return 1;
    }

    int rd;
    int licznik = rd;
    int seek2 = lseek(fd,-MAX,SEEK_END);
    while(rd = read(fd,buf,MAX)){
       
        for (int i = rd; i > 0; i--)
        {
            printf("%c",buf[i]);
        }
        printf("\nOD tyłu\n\n");
        for (int i = rd; i > 0; i--)
        {
            if(buf[i]=='\n' || i==1){
                if (i==1){
                    printf("\n");
                }
                for (int d=i;d<licznik;d++){
                    printf("%c",buf[d]);
                }
                    licznik = i;
            }
        }
        int seek = lseek(fd,-rd*2,SEEK_CUR);
    }
    return 0;
}
