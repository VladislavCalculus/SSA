#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>
#include <signal.h>
#include <time.h>

void handle_cpu_limit(int sig) {
    printf("\nВстановнелий час ЦП вичерпано.\n");
    exit(0);
}

void draw_lottery(int count, int max_val) {
    int numbers[max_val + 1];
    for (int i = 0; i <= max_val; i++) numbers[i] = 0;

    int found = 0;
    printf("Результат (%d із %d): ", count, max_val);
    while (found < count) {
        int n = (rand() % max_val) + 1;
        if (numbers[n] == 0) {
            numbers[n] = 1;
            printf("%d ", n);
            found++;
        }
    }
    printf("\n");
}

int main() {
    signal(SIGXCPU, handle_cpu_limit);

    struct rlimit rl;
    rl.rlim_cur = 1;
    rl.rlim_max = 2;

    if (setrlimit(RLIMIT_CPU, &rl) == -1) {
        perror("Помилка встановлення ліміту");
        return 1;
    }

    srand(time(NULL));
    printf("Ліміт ЦП: %ld сек.\n", (long)rl.rlim_cur);

    unsigned long long tickets = 0;
    while (1) {
        tickets++;
        printf("Квиток №%llu | ", tickets);
        draw_lottery(7, 49);
        printf("           | ");
        draw_lottery(6, 36);
    }

    return 0;
}
