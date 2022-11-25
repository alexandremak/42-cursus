/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 22:06:02 by amak              #+#    #+#             */
/*   Updated: 2022/11/25 01:24:49 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	long	count;
	long	*pointer;

	count = 234;
	pointer = &count;
	printf("printf: %i \n ", printf(" %p ", pointer));
	printf("ft_printf: %i", ft_printf(" %p ", pointer));
	return (0);
}

// gcc -Wall -Wextra -Werror main.c ft_printf.c pf_putchar.c pf_putnbrbase.c pf_putnbr_un.c pf_putnbr_ptr.c pf_putstr.c ft_strlen.c && ./a.out

// 30:     TEST(6, print(" %p %p ", LONG_MIN, LONG_MAX));
// 32:     TEST(8, print(" %p %p ", ULONG_MAX, -ULONG_MAX));
// 33:     TEST(9, print(" %p %p ", 0, 0));
