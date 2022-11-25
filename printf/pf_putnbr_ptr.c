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

long	pf_putnbr_ptr(long n, char *base)
{
	long	result;

	result = 0;
	if (((int)ft_strlen(base) > 1))
	{
		if (n < 0)
		{
			n = n + 9223372036854775807 + 1;
			result += pf_putnbr_ptr(n, base);
		}
		else if (n >= (int)ft_strlen(base))
		{
			result += pf_putnbr_ptr(n / (int)ft_strlen(base), base);
			result += pf_putnbr_ptr(n % (int)ft_strlen(base), base);
		}
		else
			result += write (1, &base[n], 1);
	}
	return (result);
}
