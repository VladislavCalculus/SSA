#include <stdio.h>
#include <stdlib.h>

int main() {
    void *p1 = realloc(NULL, 100);
    if (p1 != NULL) {
        printf("realloc(NULL, 100): %p\n", p1);
    }

    void *p2 = realloc(p1, 0);
    printf("realloc(p1, 0): %p\n", p2);
    printf("Пам'ять за адресою %p звільнена.\n", p1);
    return 0;
}
