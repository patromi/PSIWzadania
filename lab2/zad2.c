#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
int main(int argc, char *argv[]) {

    printf("Początek");
    int proc1 = fork();
    printf("Koniec\n");
    return 0;

}