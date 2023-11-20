#include "ft_printf.h"
#include <limits.h>

// int main() {
// 	char c = 'O';
// 	char* string = "boo";
// 	int num = INT_MIN;
// 	unsigned int u_num = UINT_MAX;
// 	void* ptr = malloc(sizeof(int));

// 	int count = ft_printf("FT_printf: %% %c %s %i %u %x %X %p |\n", c, string, num, u_num, 17, 666, ptr);
// 	int	count2 = printf("OG_printf: %% %c %s %i %u %x %X %p |\n", c, string, num, u_num, 17, 666, ptr);
// 	printf("FT: %i\n", count);
// 	printf("OG: %i\n", count2);

// 	return 0;
// }

int main() {
    // Test 1: %
    char c = 'O';
    int count = ft_printf("FT_printf: %% |\n");
    int count2 = printf("OG_printf: %% |\n");
    printf("FT: %i\nOG: %i\n\n", count, count2);

    // Test 2: character, string, and integers
    char* string = "boo";
    int num = INT_MIN;
    unsigned int u_num = UINT_MAX;
    int count3 = ft_printf("FT_printf: %c %s %i %u |\n", c, string, num, u_num);
    int count4 = printf("OG_printf: %c %s %i %u |\n", c, string, num, u_num);
    printf("FT: %i\nOG: %i\n\n", count3, count4);

    // Test 3: hexadecimal and pointer
    void* ptr = malloc(sizeof(int));
    int count5 = ft_printf("FT_printf: %x %p |\n", 666, ptr);
    int count6 = printf("OG_printf: %x %p |\n", 666, ptr);
    printf("FT: %i\nOG: %i\n\n", count5, count6);

    // Test 4: Mix
    int count7 = ft_printf("FT_printf: %c %s %i %u %x %X %p |\n", c, string, num, u_num, 17, 666, ptr);
    int count8 = printf("OG_printf: %c %s %i %u %x %X %p |\n", c, string, num, u_num, 17, 666, ptr);
    printf("FT: %i\nOG: %i\n\n", count7, count8);

    int count9 = ft_printf("FT_printf: %p |\n", NULL);
    int count10 = printf("OG_printf: %p |\n", NULL);
    printf("FT: %i\nOG: %i\n\n", count9, count10);

    // Clean up: Free allocated memory
    free(ptr);

    return 0;
}
