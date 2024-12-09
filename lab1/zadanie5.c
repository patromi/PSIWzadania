#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#define MAX 512
int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("Za mało argumentów.\n");
        return 1;
    }

    char buf[MAX];
    int fd = open(argv[1], O_RDWR);
    if (fd == -1) {
        perror("Nie można otworzyć pliku");
        return 1;
    }

    int start = 0;
    int start_max=0;
    int end_max = 0;
    int current = 0;
    int licznik = 0;
    int rd;
    int max_dlugosc=0;

    while ((rd = read(fd, &buf[0], MAX)) > 0) {
        current = lseek(fd, 0, SEEK_CUR);

        for (int i = 0; i < rd; i++) {
            if (buf[i] == '\n') {
                licznik = i;
                if (licznik-start > max_dlugosc){
                    max_dlugosc = licznik-start;
                    start_max = start;
                    end_max = i;
                } 
                start = licznik;


            }
        }


    }
    lseek(fd,start_max,SEEK_SET);
    rd = read(fd, buf, max_dlugosc);
    for(int i=0;i<max_dlugosc;i++){
        printf("%c",buf[i]);
    }
    printf("\nmax pozycja: %d\n", max_dlugosc);
    printf("max start: %d\n", start_max);
    printf("max end: %d\n", end_max);
                

    if (rd == -1) {
        perror("Błąd podczas odczytu pliku");
    }

    close(fd);
    return 0;
}
