/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 22:00:19 by amak              #+#    #+#             */
/*   Updated: 2022/11/24 23:23:58 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

# include <stdio.h>

int		pf_putchar(char c);
int		pf_putstr(char *s);
size_t	ft_strlen(const char *str);
int		pf_putnbrbase(int n, char *base);
long	pf_putnbr_un(long n, char *base);
int		ft_printf(const char *input, ...);

#endif
