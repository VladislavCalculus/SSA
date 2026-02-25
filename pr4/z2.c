#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>
#include <string.h>

int main() {
    int xa = 1048576;
    int xb = 3000;

    int num = xa * xb;

    printf("xa: %d, xb: %d\n", xa, xb);
    printf("Обчислене num: %d\n", num);
    printf("Розмір size_t: %zu байтів\n", sizeof(size_t));

    void *ptr = malloc(num);

    if (ptr == NULL) {
        printf("NULL: Помилка: %s\n", strerror(errno));
    } else {
        printf("УСПІХ:  %p\n", ptr);
        free(ptr);
    }

    return 0;
}
