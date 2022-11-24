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

long	pf_putnbr_un(long n, char *base)
{
	long	result;

	result = 0;
	if (((int)ft_strlen(base) > 1))
	{
		if (n < 0)
		{
			n += 4294967296;
			result += pf_putnbr_un(n, base);
		}
		else if (n >= (int)ft_strlen(base))
		{
			result += pf_putnbr_un(n / (int)ft_strlen(base), base);
			result += pf_putnbr_un(n % (int)ft_strlen(base), base);
		}
		else
			result += write (1, &base[n], 1);
	}
	return (result);
}
