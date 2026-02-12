#include <stdio.h>
#include <stdlib.h>

int global = 7;
int bss;

void check_stack(int depth) {
    int arr[1000];
    printf("Стек на глибині %d: %p\n", depth, (void*)&arr);
    if (depth < 3) check_stack(depth + 1);
}

int main() {
    int stack;
    int *heap = malloc(sizeof(int));

    printf("\nАдреси сегментів\n");
    printf("Текст (функція main): %p\n", (void*)main);
    printf("Дані (global_var): %p\n", (void*)&global);
    printf("BSS: %p\n", (void*)&bss);
    printf("Купа: %p\n", (void*)heap);
    printf("Початкова вершина стека:%p\n", (void*)&stack);
    
    printf("\nРіст стеку\n");
    check_stack(1);

    free(heap);
    return 0;
}
