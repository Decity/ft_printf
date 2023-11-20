#ifndef FT_PRINTF_LIB_H
#define FT_PRINTF_LIB_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

// main function
int ft_printf(const char *format, ...);

// print functions
int	print_c(char chr);
int	print_s(char* str);
int	print_i(int num);
int	print_u(unsigned long long int num);
int print_x(unsigned long long int num, char upper_lower);
int print_p(void* ptr);

// helper functions
int ft_strlen(char* str);
size_t hex_len(unsigned long long int num);

#endif
