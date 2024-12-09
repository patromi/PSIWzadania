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
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {

    struct msgbuf {
        long mtype;
        char mtext[20];
    } msg, msg2;

    int ip = msgget(0x2137, 0666 | IPC_CREAT);
    int f = fork();

    if (f!=0){

        for (int i = 0; i <= 10; ++i) {
            msg.mtype = i;

            char buf[10];

            for (int j = 0; j < 10; ++j) {
                buf[j] = '61' + i;
            }
            strncpy(msg.mtext, buf, sizeof(msg.mtext) - 1);
            printf("Wysyłam %s\n", msg.mtext);
            msgsnd(ip, &msg, 15, IPC_NOWAIT);
            perror("err");
        }

    }else{
        long num =  atoi(argv[1]);
        printf("Odbieram %ld\n", num);
        msgrcv(ip, &msg2, 15,num, IPC_NOWAIT);
        printf("Odebrano: %s\n", msg2.mtext);

    }





    return 0;
}