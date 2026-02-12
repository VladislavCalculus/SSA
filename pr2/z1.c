#include <stdio.h>
#include <time.h>
#include <limits.h>

int main() {
    printf("Розмір time_t: %zu байт (%zu біт)\n", sizeof(time_t), sizeof(time_t) * 8);

    if (sizeof(time_t) <= 4) {
        time_t max_32 = 2147483647; // Максимальне значення для signed int32
        printf("Максимальний час (32-біт): %s\n", ctime(&max_32));
        max_32++;
        printf("Після переповнення: %s\n", ctime(&max_32));
    } else {
        time_t max_64 = 2147483647;
	while(ctime(&max_64) != NULL) {
		max_64 += 1000000000000;
        	printf("Максимальний час (64-біт): %s\n", ctime(&max_64));
	}
    }
    return 0;
}
