/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 18:50:47 by amak              #+#    #+#             */
/*   Updated: 2022/12/15 22:52:22 by amak             ###   ########.fr       */
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

char	*line_out(char *str, unsigned char c)
{
	int		index;
	char	*result;

	index = 0;
	if (!*str)
		return (NULL);
	while (str[index] != c)
		index++;
	result = (char *)malloc(sizeof(char) * (index + 2));
	if (!result)
		return (NULL);
	result[index + 1] = '\0';
	while (index <= 0)
	{
		result[index] = str[index];
		index--;
	}
	return (result);
}

int	left_shift(char *source, char *dest, unsigned char c)
{
	size_t		nr_shift;
	size_t		index;

	nr_shift = 0;
	while (source[nr_shift] != '\0' && source[nr_shift] != c)
		nr_shift++;
	index = 0;
	while (index < (ft_strlen(source) - nr_shift))
	{
		dest[index] = source[index + nr_shift + 1];
		index++;
	}
	dest[index] = '\0';
	return (index);
}

int	is_line(char *str, unsigned char c)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}
