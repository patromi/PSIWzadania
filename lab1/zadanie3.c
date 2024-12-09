#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#define MAX 512
int main(int argc, char *argv[]) {

    if (argc <3) {
    printf( " Za malo argumentow  ");
    return 1;
} 
    char buf[MAX];
    int fd1 = open(argv[1],O_RDONLY);
    int fd2 = open(argv[2],O_WRONLY);
    if (fd1==-1 && fd2 == -1 ){
        return 1;
    }

    int rd;
    while(rd = read(fd1,buf,MAX)){
        write(fd2,buf,rd);
    }

    return 0;
}
