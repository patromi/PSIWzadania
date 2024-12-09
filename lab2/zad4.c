#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
int main(int argc, char *argv[]) {
    execlp("ls", "ls", "lab2","-l", NULL);
    printf("Początek\n");
    printf("Koniec\n");

    return 0;}