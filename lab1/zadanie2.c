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
    while(rd = read(fd,buf,MAX)){
        printf("%d\n",rd);

        for (int i = 0; i < MAX; i++)
        {
            // printf("%s",buf[i]);
            if (buf[i] == 'x'){
                buf[i] = 'X';
            }
        }

        int seek = lseek(fd,-rd,SEEK_CUR);
        printf("%d\n",seek);
        write(fd,buf,rd);
    }

    return 0;
}
