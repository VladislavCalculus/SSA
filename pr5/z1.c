#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Data {
    int id;
    char buffer[1024];
};

int main() {
    struct Data *base_ptr = malloc(sizeof(struct Data));
    if (!base_ptr) return 1;

    base_ptr->id = 42;
    strcpy(base_ptr->buffer, "данніданніданніданні");

    printf("malloc addr: %p\n", (void*)base_ptr);

    char *inside_ptr = base_ptr->buffer;
    printf("Вказівник всередину: %p (зсув: %ld)\n", 
            (void*)inside_ptr, (long)(inside_ptr - (char*)base_ptr));

    printf("\nfree(inside_ptr)\n");

    free(inside_ptr);
    printf("Цей текст ніколи не буде надрукований. :)\n");

    return 0;
}
