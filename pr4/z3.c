#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("malloc(0)\n");
    void *ptr = malloc(0);

    if (ptr == NULL) {
        printf("Результат: NULL\n");
    } else {
        printf("Результат: %p\n", ptr);
        printf("Звільнення пам'яті\n");
        free(ptr);
        printf("Очищено\n");
    }

    return 0;
}
