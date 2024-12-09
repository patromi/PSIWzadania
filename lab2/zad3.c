#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
int main(int argc, char *argv[]) {
    printf("Początek\n");
    execlp("ls", "ls", "lab2","-l", NULL);
    printf("Koniec\n");

    return 0;}