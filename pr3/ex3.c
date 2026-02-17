#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include <errno.h>

int main() {
    signal(SIGXFSZ, SIG_IGN);

    FILE *f = fopen("dice_results.txt", "w");
    if (f == NULL) {
        perror("Помилка відкриття файлу");
        return 1;
    }

    srand(time(NULL));

    int count = 0;
    while (1) {
        int res = fprintf(f, "Кидок №%d: %d\n", ++count, (rand() % 6) + 1);

        if (fflush(f) != 0) {
            printf("\nLіміт розміру файлу.");
            break;
        }

        if (ferror(f)) {
            printf("\nЗапис зупинено.\n");
            break;
        }

        printf(".");
        fflush(stdout);
    }

    fclose(f);
    printf("\nВсього записів: %d\n", count);
    return 0;
}
