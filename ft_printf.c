/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebayat <ebayat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:56:03 by elie              #+#    #+#             */
/*   Updated: 2023/11/28 13:48:06 by ebayat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parse_conversion(char c, va_list args){

	if (c == 'c')
		return (print_c(va_arg(args, int)));
	if (c == 's')
		return (print_s(va_arg(args, char*)));
	if (c == 'p')
		return (print_p(va_arg(args, void*)));
	if (c == 'd' || c == 'i')
		return (print_i(va_arg(args, int)));
	if (c == 'u')
		return (print_u(va_arg(args, unsigned int)));
	if (c == 'x')
		return (print_x(va_arg(args, unsigned int), 'l'));
	if (c == 'X')
		return (print_x(va_arg(args, unsigned int), 'u'));
	if (c == '%'){
		return (print_c('%'));}

	// TODO: find out of this requires error handling for wrong format
	return (0);
}


int	ft_printf(const char *printf_str, ...)
{
	va_list args;
	va_start(args, printf_str);
	size_t	character_counter = 0;

	while (*printf_str)
	{
		if (*printf_str == '%'){	// Check for %, if found, parse the conversion // TODO check for invalid input
			printf_str++;
			if (*printf_str == '\0')
				return (-1);
			character_counter += parse_conversion(*printf_str, args);
		} else {
			character_counter += write(1, printf_str, 1);
		}
		printf_str++;
	}
	va_end(args);

	return (character_counter);
}
