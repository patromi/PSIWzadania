#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include "signal.h"
#include "sys/wait.h"
//7. Zrealizować następujące potoki:
//• finger | cut -d' ' -f1
//• ls -l | grep ^d | more
//• ps –ef| tr -s ' ' :| cut -d: -f1 |sort| uniq -c |sort n
//• cat /etc/group | head -5 > grupy.txt

int main(int argc, char *argv[]) {

    int fd[2];
    int rura = pipe(fd);

    if (fork() == 0 ){
        close(fd[0]);
        dup2(fd[1], 1);
        execlp("ls","ls",NULL);

    }
    else{
        close(fd[1]);
        dup2(fd[0], 0);
        execlp("tr","tr","a-z","A-Z",NULL);
    }





    return 0;
}
