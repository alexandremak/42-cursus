/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 22:00:19 by amak              #+#    #+#             */
/*   Updated: 2022/11/25 01:23:27 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

# include <stdio.h>

# define DEC "0123456789"
# define LHEX "0123456789abcdef"
# define UHEX "0123456789ABCDEF"

int		pf_putchar(char c);
int		pf_putstr(char *s);
size_t	ft_strlen(const char *str);
int		pf_putnbrbase(int n, char *base);
long	pf_putnbr_un(long n, char *base);
long	pf_putnbr_ptr(long n, char *base);
int		ft_printf(const char *input, ...);

#endif
