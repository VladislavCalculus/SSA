#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    void *ptr = NULL;
    int iteration = 0;

    while (iteration < 2) {
        printf("\niтерація: %d\n", iteration);

        if (!ptr) {
            printf("Викликаю malloc...\n");
            ptr = malloc(100);
            strcpy((char*)ptr, "Дані ітерації");
        } else {
            printf("malloc НЕ викликано!: %p\n", ptr);
        }

        printf("ptr: %s\n", (char*)ptr);

        printf("free(ptr)\n");
        free(ptr);
        iteration++;
    }

    return 0;
}
