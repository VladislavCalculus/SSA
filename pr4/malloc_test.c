#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>
#include <string.h>

void test_malloc(size_t bytes, const char* description) {
    printf("Trying to allocate %-15s (%zu bytes)... ", description, bytes);
    void* ptr = malloc(bytes);

    if (ptr) {
        printf("SUCCESS\n");
        free(ptr);
    } else {
        printf("FAIL: %s\n", strerror(errno));
    }
}

int main() {
    printf("System info: %zu-bit architecture\n", sizeof(size_t) * 8);
    printf("--------------------------------------------------\n");
    test_malloc(SIZE_MAX, "SIZE_MAX");
    test_malloc((size_t)1 << 63, "2^63 (8 Eb)");
    test_malloc(((size_t)1 << 63) - 1, "2^63 - 1");
    test_malloc((size_t)1 << 47, "2^47 (128 Tb)");
    test_malloc((size_t)1 << 30, "1 Gb");

    return 0;
}
