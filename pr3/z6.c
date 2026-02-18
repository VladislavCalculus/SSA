#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <signal.h>

void handle_segfault(int sig) {
    printf("\nСтек переповнено.\n");
    exit(1);
}

void recursive_function(int depth) {
    char buffer[1024];
    if (depth % 10 == 0) {
        printf("Глибина: %d\n", depth);
    }
    recursive_function(depth + 1);
}

int main() {
    struct rlimit rl;

    signal(SIGSEGV, handle_segfault);

    if (getrlimit(RLIMIT_STACK, &rl) == 0) {
        printf("Початковий стек: %ld KB\n", rl.rlim_cur / 1024);
    }

    stack_t ss;
    ss.ss_sp = malloc(SIGSTKSZ);
    ss.ss_size = SIGSTKSZ;
    ss.ss_flags = 0;
    sigaltstack(&ss, NULL);

    struct sigaction sa;
    sa.sa_handler = handle_segfault;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_ONSTACK;
    sigaction(SIGSEGV, &sa, NULL);

    rl.rlim_cur = 64 * 1024;
    if (setrlimit(RLIMIT_STACK, &rl) == -1) {
        perror("setrlimit");
        return 1;
    }
    printf("Новий ліміт: 64 KB\n");

    recursive_function(1);

    return 0;
}
