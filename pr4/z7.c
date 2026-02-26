#include <stdlib.h>
#include <stdio.h>

struct sbar {
    int id;
    char data[64];
};

int main() {
    struct sbar *ptr, *newptr;
    ptr = calloc(1000, sizeof(struct sbar));
    if (!ptr) return 1;

    newptr = reallocarray(ptr, 500, sizeof(struct sbar));

    if (newptr != NULL) {
        ptr = newptr;
        printf("\nВиділено 500 елементів\n");
    } else {
        free(ptr);
        return 1;
    }

    free(ptr);
    return 0;
}
