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

long	pf_putnbr_ptr(size_t n, char *base, size_t size_b)
{
	long	result;

	result = 0;
	if (n >= size_b)
	{
		result += pf_putnbr_ptr(n / size_b, base, size_b);
		result += pf_putnbr_ptr(n % size_b, base, size_b);
	}
	else
		result += write (1, &base[n], 1);
	return (result);
}
