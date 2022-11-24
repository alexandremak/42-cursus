/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 21:59:28 by amak              #+#    #+#             */
/*   Updated: 2022/11/23 22:40:56 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static	void	print_condition(char c, void *variable)
{
	long	number;

	if (c == '%')
		write(1, "%", 1);
	else if (c == 'c')
		write (1, &variable, 1);
	else if (c == 'd')
	{
		number = (long)*variable;
		ft_putnbr_fd((, 1);
	}
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
			print_condition(input[pos + 1], va_arg(arguments, void *));
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