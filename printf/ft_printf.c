/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 21:59:28 by amak              #+#    #+#             */
/*   Updated: 2022/11/24 23:32:10 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	print_condition(char c, va_list args)
{	
	if (c == '%')
		return (write(1, "%", 1));
	if (c == ' ')
		return (write(1, " ", 1));
	else if (c == 'c')
		return (pf_putchar((unsigned char)va_arg(args, int)));
	else if (c == 's')
		return (pf_putstr(va_arg(args, char *)));
	// else if (c == 'p')
	// 	(va_arg(args, void *);
	else if (c == 'd' || c == 'i')
		return (pf_putnbrbase(va_arg(args, int), "0123456789"));
	else if (c == 'u')
		return (pf_putnbr_un(va_arg(args, int), "0123456789"));
	else if (c == 'x')
		return (pf_putnbr_un(va_arg(args, int), "0123456789abcdef"));
	else if (c == 'X')
		return (pf_putnbr_un(va_arg(args, int), "0123456789ABCDEF"));
	else
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

// cspdiuxX%