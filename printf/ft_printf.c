/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 21:59:28 by amak              #+#    #+#             */
/*   Updated: 2022/11/25 22:31:40 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	print_condition(char c, va_list args)
{
	long long	number;

	if (c == '%')
		return (write(1, "%", 1));
	if (c == 'c')
		return (pf_putchar((unsigned char)va_arg(args, int)));
	if (c == 's')
		return (pf_putstr(va_arg(args, char *)));
	if (c == 'p')
	{
		number = (long long)va_arg(args, void *);
		if (!number)
			return (write(1, "(nil)", 5));
		write (1, "0x", 2);
		return ((pf_putnbr_ptr(number, LHEX, 16)) + 2);
	}
	if (c == 'd' || c == 'i')
		return (pf_putnbrbase(va_arg(args, int), DEC, 10));
	if (c == 'u')
		return (pf_putnbr_un(va_arg(args, unsigned int), DEC, 10));
	if (c == 'x')
		return (pf_putnbr_un(va_arg(args, int), LHEX, 16));
	if (c == 'X')
		return (pf_putnbr_un(va_arg(args, int), UHEX, 16));
	return (0);
}

int	ft_printf(const char *input, ...)
{
	int		result;
	va_list	arguments;
	int		pos;

	result = 0;
	va_start(arguments, input);
	pos = 0;
	while (input[pos] != '\0')
	{
		if (input[pos] == '%')
		{
			result += print_condition(input[pos + 1], arguments);
			pos++;
		}
		else
		{
			write(1, &input[pos], 1);
			result++;
		}
		pos++;
	}
	return (result);
}
