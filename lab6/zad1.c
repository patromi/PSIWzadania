#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

int main(int argc, char *argv[]) {
    struct msgbuf {
        long mtype;
        char mtext[20];
    } msg,msg2;


    strncpy(msg.mtext, "hello world", sizeof(msg.mtext) - 1);
    msg.mtype = 1;
    int ip = msgget(0x2137, 0666 | IPC_CREAT);

    int f = fork();
    printf("%d\n", f);
    if (f==0) {
        msgsnd(ip, &msg, 11, IPC_NOWAIT);
    } else{
        msgrcv(ip, &msg2, 11, 0, IPC_NOWAIT);
        perror("err");
        printf("Odebrano: %s\n", msg2.mtext);
    }

    return 0;
}