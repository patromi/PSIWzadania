#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include "signal.h"
#include <sys/wait.h>


int main(int argc, char *argv[]) {
    char buf[512];
    int rd;
    int fd[2];
    int rura = pipe(fd);
    int f1 = fork();
    if (f1 == 0 ) {
        dup2 ( fd [1] , 1) ;
        execvp ("ls" ,  0) ;
    }
    else{
        close ( fd [1]) ;
        dup2(fd[0], 0);
        while ((rd = read(fd[0], buf, 512)) > 0) {
            for (int i = 0; i < rd; i++) {
                if (1==1) {
                    if (buf[i] >= 97 && buf[i] <=122){
                        buf[i] = buf[i] - 32;
                    }


                }
            }
            for (int i = 0; i < rd; i++) {
                printf("%c",buf[i]);
            }

        }
        wait(NULL);
    }

    return 0;
}
