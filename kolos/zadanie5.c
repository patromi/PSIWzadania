#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>
//Napisać program tworzący dwa procesy: klienta i serwera. Serwer tworzy
//ogólnodostępną kolejkę FIFO, i czeka na zgłoszenia klientów. Każdy klient tworzy
//własną kolejkę, poprzez którą będą przychodzić odpowiedzi serwera. Zadaniem
//klienta jest przesłanie nazwy stworzonej przez niego kolejki, a serwera odesłaniem
//poprzez kolejkę stworzoną przez klienta wyniku polecenia ls.
int main(int argc, char *argv[]) {

    unlink("client");
    unlink("server");
    mkfifo("server", 0666);

    //client
    if (fork() == 0 ){

        char name[] = "client";
        if (mkfifo("client", 0666) == -1 && errno != EEXIST) {
            perror("mkfifo client");
            exit(EXIT_FAILURE);
        }

        int server = open("server", O_WRONLY);
        write(server,name,7);
        close(server);
        int client = open("client",O_RDONLY);
        char buf[512];

        dup2(client,0);
        read(client,buf,512);
        printf("odebrano %s\n",buf);
        exit(0);
    }

    //serwer
    if (fork() == 0 ){

        int serwer = open("server",O_RDONLY);
        char buf[20];
        read(serwer,buf,20);
        printf("buffer %s\n",buf);
        close(serwer);

        int client = open("client",O_WRONLY);
        dup2(client,STDOUT_FILENO);
        execlp("ls","ls","-la",buf,NULL);
        exit(0);


    }
    wait(NULL);
    wait(NULL);

    return 0;
}
