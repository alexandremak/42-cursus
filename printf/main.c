/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 22:06:02 by amak              #+#    #+#             */
/*   Updated: 2022/11/24 23:32:40 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	// long	count;
	// long	*pointer;

	// count = 234;
	// pointer = &count;
	// printf("%ln", pointer);
	printf("printf: %i \n ", printf(" %x ", -100));
	printf("ft_printf: %i", ft_printf(" %x ", -100));
	return (0);
}

// gcc -Wall -Wextra -Werror main.c ft_printf.c pf_putchar.c pf_putnbrbase.c pf_putnbr_un.c pf_putstr.c ft_strlen.c && ./a.out