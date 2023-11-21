#include "ft_printf.h"

int main() {
    // Test 1: %
    char c = 'O';
    int count1 = ft_printf("FT_printf: %% |\n");
    int count2 = printf("OG_printf: %% |\n");
    printf("FT: %i\nOG: %i\n\n", count1, count2);

    // Test 2: character, string, and integers
    char* string = "boo";
	char* null_string = NULL;
    int num = INT_MIN;
    unsigned int u_num = UINT_MAX;
    count1 = ft_printf("FT_printf: %c %s %i %u %s |\n", c, string, num, u_num, null_string);
    count2 = printf("OG_printf: %c %s %i %u %s |\n", c, string, num, u_num, null_string);
    printf("FT: %i\nOG: %i\n\n", count1, count2);

    // Test 3: hexadecimal and pointer
    void* ptr = malloc(sizeof(int));
    count1 = ft_printf("FT_printf: %x %p |\n", 666, ptr);
    count2 = printf("OG_printf: %x %p |\n", 666, ptr);
    printf("FT: %i\nOG: %i\n\n", count1, count2);

    // Test 4: Mix
    count1 = ft_printf("FT_printf: %c %s %i %u %x %X %p |\n", c, string, num, u_num, 17, 666, ptr);
    count2 = printf("OG_printf: %c %s %i %u %x %X %p |\n", c, string, num, u_num, 17, 666, ptr);
    printf("FT: %i\nOG: %i\n\n", count1, count2);

    count1 = ft_printf("FT_printf: %p |\n", NULL);
    count2 = printf("OG_printf: %p |\n", NULL);
    printf("FT: %i\nOG: %i\n\n", count1, count2);



    // Clean up: Free allocated memory
    free(ptr);

    return 0;
}
