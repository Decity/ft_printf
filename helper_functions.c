#include "ft_printf.h"

int		ft_strlen(char* str){
	int	i = 0;
	while (*str++)
		i++;
	return (i);
}

size_t	hex_len(unsigned long long int num){
	size_t	len = 0;

	if (num == 0)
		return (1);
	while (num){
		num /= 16;
		len++;
	}
	return (len);
}
