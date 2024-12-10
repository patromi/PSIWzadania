#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>
//Napisać program tworzący pierścień procesów połączonych za pomocą kolejki FIFO.
//Liczbę procesów w pierścieniu podaje użytkownik. Jeden z procesów ma
//zainicjalizować wysłanie komunikatu, a pozostałe odczytać go, wyświetlić na ekranie
//i wysłać dalej, dopisując do komunikatu własny identyfikator.
    




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
        while (1){
            int client = open("client",O_WRONLY);
            write(client,"ps",2);
            close(client);
            client = open("client",O_RDONLY);
            dup2(client,0);
            char buf[512];
            read(client,buf,512);
            printf("odebrano %s\n",buf);
            break;
        }
        exit(0);
    }

    //serwer
    if (fork() == 0 ){

        int serwer = open("server",O_RDONLY);
        char buf[20];
        read(serwer,buf,20);
        printf("buffer %s\n",buf);
        close(serwer);
        while (1){
            int client = open(buf,O_RDONLY);
            char buf2[10];

            read(client,buf2,10);
            close(client);
            if (fork()==0){
                int client = open(buf,O_WRONLY);
                dup2(client,STDOUT_FILENO);

                execlp(buf2,buf2,NULL);
            }
            else{
                wait(NULL);
        }
        exit(0);
    }}
    wait(NULL);
    wait(NULL);

    return 0;
}
