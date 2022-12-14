/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 18:50:47 by amak              #+#    #+#             */
/*   Updated: 2023/01/07 17:11:23 by amak             ###   ########.fr       */
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

char	*ft_strchr(const char *s, int c)
{
	int		pos;
	char	*str;

	pos = 0;
	str = (char *)s;
	while (str[pos])
	{
		if (str[pos] == (unsigned char)c)
			return (&str[pos]);
		pos++;
	}
	if (str[pos] == (char)c)
		return (&str[pos]);
	return (NULL);
}
