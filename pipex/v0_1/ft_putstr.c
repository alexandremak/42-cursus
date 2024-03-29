/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 15:16:23 by amak              #+#    #+#             */
/*   Updated: 2023/03/04 15:36:47 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_putstr(char *s)
{
	int		pos;

	pos = 0;
	while (s[pos])
	{
		write(1, &s[pos], 1);
		pos++;
	}
}
