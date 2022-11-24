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

int	pf_putnbrbase(int n, char *base)
{
	int	result;

	result = 0;
	if (((int)ft_strlen(base) > 1))
	{
		if (n == -2147483648)
		{
			result += write(1, "-", 1);
			result += pf_putnbrbase(2, base);
			result += pf_putnbrbase(147483648, base);
		}
		else if (n < 0)
		{
			result += write (1, "-", 1);
			result += pf_putnbrbase(-n, base);
		}
		else if (n >= (int)ft_strlen(base))
		{
			result += pf_putnbrbase(n / (int)ft_strlen(base), base);
			result += pf_putnbrbase(n % (int)ft_strlen(base), base);
		}
		else
			result += write (1, &base[n], 1);
	}
	return (result);
}
