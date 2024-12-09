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
    int licznik = 0;

    for (int i = 1; i < argc; i++) {
        int fd = open(argv[i], O_RDWR);
        if (fd == -1) {
            perror("Nie można otworzyć pliku");
            return 1;
        }

        int rd;
        while ((rd = read(fd, buf, MAX)) > 0) {
            licznik += rd;
        }

        if (rd == -1) {
            perror("Błąd podczas odczytu pliku");
            close(fd);
            return 1;
        }

        printf("Plik o nazwie %s ma rozmiar %d B\n", argv[i], licznik);
        licznik = 0;
        close(fd);
    }

    return 0;
}
