#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include "signal.h"
#include <sys/wait.h>



int main(int argc, char *argv[]) {

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
            execlp("tr","tr","a-z","A-Z", 0);
            wait(NULL);
    }

    return 0;
}
