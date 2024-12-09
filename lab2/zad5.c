#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
int main(int argc, char *argv[]) {
    int proc1 = fork();
    wait(NULL);
    if (proc1 == 0) {
        printf("\n-------Początek listy--------\n");
        execlp("ps", "ps", "-eo","comm", NULL);
    }
    printf("\n--------Koniec Procesów--------------\n");

    return 0;}