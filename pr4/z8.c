#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("\nРозширення\n");
    void *p1 = malloc(128);
    printf("Початкова адреса: %p\n", p1);

    void *p1_new = realloc(p1, 256);
    printf("Нова адреса: %p\n", p1_new);
    if (p1 == p1_new) printf("Результат: блок розширено\n");

    printf("\nґтКопіювання\n");
    void *p2 = malloc(128);
    void *blocker = malloc(128);
    printf("Початкова адреса p2: %p\n", p2);
    printf("Адреса затички: %p\n", blocker);

    void *p2_new = realloc(p2, 1024 * 1024);
    printf("Нова адреса p2: %p\n", p2_new);

    if (p2 != p2_new) {
        printf("Результат: дані в новому блоці\n");
    }

    free(p1_new);
    free(blocker);
    free(p2_new);
    return 0;
}
