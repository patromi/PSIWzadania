#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <pwd.h>
#include <grp.h>

void display_permissions(mode_t mode) {
    const char *permissions = "rwxrwxrwx";
    printf("Permissions: ");
    for (int i = 0; i < 9; i++) {
        printf((mode & (1 << (8 - i))) ? "%c" : "-", permissions[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <pathname>\n", argv[0]);
        return 1;
    }

    struct stat sb;
    if (stat(argv[1], &sb) == -1) {
        perror("stat");
        return 1;
    }

    printf("Name: %s\n", argv[1]);
    struct passwd *pwd = getpwuid(sb.st_uid);
    printf("Owner: %-8s\n", pwd ? pwd->pw_name : "(unknown)");

    struct group *grp = getgrgid(sb.st_gid);
    printf("Group: %-8s\n", grp ? grp->gr_name : "(unknown)");

    display_permissions(sb.st_mode);

    printf("Type: ");
    switch (sb.st_mode & S_IFMT) {
        case S_IFBLK:  printf("block device\n");    break;
        case S_IFCHR:  printf("character device\n");break;
        case S_IFDIR:  printf("directory\n");       break;
        case S_IFIFO:  printf("FIFO/pipe\n");       break;
        case S_IFLNK:  printf("symlink\n");         break;
        case S_IFREG:  printf("regular file\n");    break;
        case S_IFSOCK: printf("socket\n");          break;
        default:       printf("unknown?\n");        break;
    }

    printf("File size: %lld bytes\n", (long long) sb.st_size);
    printf("Last file modification: %s", ctime(&sb.st_mtime));

    return 0;
}
