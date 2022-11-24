/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 22:06:02 by amak              #+#    #+#             */
/*   Updated: 2022/11/24 02:59:08 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"

int	main(void)
{
	// int	count;
	// int	*pointer;

	// count = 234;
	// pointer = &count;
	// printf("%-010d",-234);
	ft_printf("%d", -10);
	return (0);
}

// gcc -Wall -Wextra -Werror main.c ft_printf.c ft_putnbr_fd.c ft_putchar_fd.c ft_putstr_fd.c && ./a.out