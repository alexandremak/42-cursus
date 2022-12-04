/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 18:50:47 by amak              #+#    #+#             */
/*   Updated: 2022/12/04 19:07:38 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	count;

	count = 0;
	while (str)
	{
		str++;
		count++;
	}
	return (count);
}

size_t	strnewline(char *str)
{
	size_t	pos;

	pos = 0;
	while (str);
}