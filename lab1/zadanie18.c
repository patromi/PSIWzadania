#include <dirent.h>
#include <stdio.h>

int main(int argc, char *argv[]) {

    struct dirent **namelist;
    int n;

    n = scandir(argv[1], &namelist, NULL, alphasort);
    if (n == -1) {
        perror("scandir");
        return 1;
    }

    n = scandir(argv[1], &namelist, NULL, alphasort);
    if (n == -1) {
        perror("scandir");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("%s\n", namelist[i]->d_name);
    }

    return 0;
}