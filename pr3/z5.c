#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void handle_limit(int sig) {
    printf("\nЛіміт файлу досягнуто\n");
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Програма потребує два аргументи (файл з/ файл в)\n");
        return 1;
    }

    signal(SIGXFSZ, handle_limit);

    FILE *src = fopen(argv[1], "r");
    if (!src) {
        fprintf(stderr, "Неможливо відкрити файл (%s) для читання\n", argv[1]);
        return 1;
    }

    FILE *dest = fopen(argv[2], "w");
    if (!dest) {
        fprintf(stderr, "Неможливо відрити файл (%s) для запису\n", argv[2]);
        fclose(src);
        return 1;
    }

    char buf[4096];
    size_t n;

    while ((n = fread(buf, 1, sizeof(buf), src)) > 0) {
        if (fwrite(buf, 1, n, dest) < n) {
            // запис неповний - ліміт ulimit
            break;
        }
    }

    fclose(src);
    fclose(dest);
    return 0;
}
