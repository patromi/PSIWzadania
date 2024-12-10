#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include "signal.h"
//Napisz program wykonujący ciągle polecenia ls i ps, tzn. zaraz po zakończeniu
//jednego polecenia ps wykonane powinno być następne polecenie ps i podobnie
//zaraz po zakończeniu polecenia ls wykonane powinno być następne polecenie ls.
//8. Zmodyfikować zadanie 7 tak, aby po otrzymaniu sygnału SIGINT polecenie ps
//przestało być wykonywane.
//9. Zmodyfikować zadanie 8 tak, aby sygnał SIGINT działał jako przełącznik – tj.
//jedno naciśnięcie klawiszy Ctrl-C powodowało zakończenie polecenia ps, a
// następne naciśnięcie tej kombinacji klawiszy wznawiało wykonanie tego
//polecenia


int flaga = 0;
void sig_int(int signo) {
    printf("SIGINT\n");
    if (flaga == 0 ){flaga=1;}
    else {flaga =0;}

}

void sig_stop(int signo) {
    printf("SIGTSP\n");
}

void sig_quit(int signo) {
    printf("SIGQUIT\n");
}

int main(int argc, char *argv[]) {

    signal(SIGINT, sig_int);

    while (1){
        sleep(1);

        if (fork() == 0){
            if (fork()==0 && flaga == 0){
                execlp("ps","ps");
            }

            execlp("ls","ls");
        }

    }

    return 0;
}
