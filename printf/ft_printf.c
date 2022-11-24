/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 21:59:28 by amak              #+#    #+#             */
/*   Updated: 2022/11/24 02:59:40 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static	void	print_condition(char c, va_list args)
{
	if (c == '%')
		write(1, "%", 1);
	else if (c == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	else if (c == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
	// else if (c == 'p')
	// 	(va_arg(args, void *);
	else if (c == 'd' || c == 'i')
		ft_putnbr_fd(va_arg(args, int), 1);
	else if (c == 'u')
		ft_putnbr_fd(va_arg(args, unsigned int), 1);
	// else if (c == 'x')
	// 	ft_putnbr_fd(va_arg(args, int), 1);
	// else if (c == 'X')
	// 	ft_putnbr_fd(va_arg(args, int), 1);
	else
		return;
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
			print_condition(input[pos + 1], arguments);
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