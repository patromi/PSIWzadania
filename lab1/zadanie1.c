#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "string.h"
#define MAX 512
int main(int argc, char *argv[]) {

    if (argc <2) {
    printf( " Za malo argumentow  ");
    return 1;
} 

    printf("Argument 1 %s",argv[1]);
    int fd = creat(argv[1],0640);
    if (fd == -1){
        return 1;
    }


    if (write( fd , argv[2] , strlen(argv[2])) == -1) {
        return 1 ;}
    
    return 0;
}
