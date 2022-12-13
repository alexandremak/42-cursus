/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 18:50:47 by amak              #+#    #+#             */
/*   Updated: 2022/12/12 20:42:56 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	count;

	count = 0;
	while (*str)
	{
		str++;
		count++;
	}
	return (count);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	int		pos;

	pos = 0;
	result = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!result)
		return (NULL);
	while (*s1)
	{
		result[pos] = *s1;
		pos++;
		s1++;
	}
	while (*s2)
	{
		result[pos] = *s2;
		pos++;
		s2++;
	}
	result[pos] = '\0';
	return (result);
}

int	ft_strline(char *str)
{
	while (*str)
	{
		if (str == '\n' || str == '\0')
			return (1);
		str++;
	}
	return (0);
}