#include "ft_printf.h"

int	print_c(char c)
{
	return (write(1, &c, 1));
}
int	print_s(char* str){
	if (!str)
		return (print_s("(null)"));
	int len = ft_strlen(str);


	if (len)
		return (write(1, str, len));
	else
		return (0);
}

int print_p(void* ptr){
	unsigned long long int address = (unsigned long long int)ptr;

	if (ptr){
		print_s("0x");
		return (2 + print_x(address, 'l'));
	}
	return (print_s("(nil)"));

} // TODO check if this prints addresses at codam. otherwise consider using uint128_t

int print_i(int n){
	int	printed = 0;

	if (n == INT_MIN)
		return (print_s("-2147483648"));
	if (n < 0)
	{
		printed += print_c('-');
		n *= -1;
	}
	if (n >= 10)
		printed += print_i(n / 10);

	return (printed + print_c(('0' + (n % 10))));
}

int print_u(unsigned long long int n){
	int	printed = 0;

	if (n >= 10)
		printed += print_u(n / 10);

	return (printed + print_c(('0' + (n % 10))));
}

int print_x(unsigned long long int num, char upper_lower){
	char*	set;
	size_t	i = hex_len(num);
	char	return_num[i + 1];
	char	lower_case[16] = "0123456789abcdef";
	char	upper_case[16] = "0123456789ABCDEF";


	if (upper_lower == 'u')
		set = upper_case;
	else if (upper_lower == 'l')
		set = lower_case;

	return_num[i] = '\0';

	i--;

	if (num == 0)
		return(print_s("0"));
	while (num){
		return_num[i] = set[num % 16];
		num /= 16;
		i--;
	}

	return (print_s(return_num));
}
