/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putnbrbase.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:13:43 by amak              #+#    #+#             */
/*   Updated: 2022/11/24 22:27:47 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_putnbrbase(int n, char *base, int size_b)
{
	int	result;

	result = 0;
	if (n == -2147483648)
	{
		result += write(1, "-", 1);
		result += pf_putnbrbase(2, base, size_b);
		result += pf_putnbrbase(147483648, base, size_b);
	}
	else if (n < 0)
	{
		result += write (1, "-", 1);
		result += pf_putnbrbase(-n, base, size_b);
	}
	else if (n >= size_b)
	{
		result += pf_putnbrbase(n / size_b, base, size_b);
		result += pf_putnbrbase(n % size_b, base, size_b);
	}
	else
		result += write (1, &base[n], 1);
	return (result);
}
