#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main() {
    size_t initial_size = 1024;
    void *ptr = malloc(initial_size);
    if (!ptr) {
        return 1;
    }
    printf("malloc: %p\n", ptr);
    size_t huge_size = (size_t)1 << 62;
    printf("realloc до %zu байтів...\n", huge_size);
    void *new_ptr = realloc(ptr, huge_size);

    if (new_ptr == NULL) {
        printf("realloc NULL (%s)\n", strerror(errno));
        printf("СТАРИЙ блок: %p\n", ptr);
        free(ptr);
        printf("free()n");
    } else {
        printf("realloc: %p\n", new_ptr);
        free(new_ptr);
    }

    return 0;
}
