/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 21:47:15 by amak              #+#    #+#             */
/*   Updated: 2023/09/08 02:09:39 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static		int	ft_isspace(char c)
{
	if (((c >= 9) && (c <= 13)) || c == 32)
		return (1);
	else
		return (0);
}

long long	ft_atoi(const char *nptr)
{
	int			pos;
	long long	sign;
	long long	res;

	pos = 0;
	sign = 1;
	res = 0;
	while (ft_isspace(nptr[pos]))
		pos++;
	if (nptr[pos] == '-' || nptr[pos] == '+')
	{
		if (nptr[pos] == '-' )
			sign = -1;
		pos++;
	}
	while (nptr[pos] >= '0' && nptr[pos] <= '9')
	{
		res = (res * 10) + (nptr[pos] - 48);
		pos++;
	}
	res = res * sign;
	return (res);
}
