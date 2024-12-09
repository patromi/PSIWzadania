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
    int seek2 = lseek(fd,-MAX,SEEK_END);
    while(rd = read(fd,buf,MAX)){
        
        for (int i = rd; i > 0; i--)
        {
            printf("%c",buf[i]);
        }

        int seek = lseek(fd,-rd*2,SEEK_CUR);
    }

    return 0;
}
