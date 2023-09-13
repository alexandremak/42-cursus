/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 18:50:47 by amak              #+#    #+#             */
/*   Updated: 2023/01/15 01:10:27 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

char	*ft_strjoin_gnl(char *line, char *buffer)
{
	size_t	line_len;
	size_t	buffer_len;
	char	*output;
	int		x;
	int		y;

	if (!buffer)
		return (NULL);
	line_len = ft_strlen_gnl(line);
	buffer_len = ft_strlen_gnl(buffer);
	output = malloc((line_len + buffer_len + 1) * sizeof(char));
	if (!output)
		return (NULL);
	x = -1;
	y = -1;
	while (++x < (int)line_len)
		output[x] = line[x];
	while (++y < (int)buffer_len)
	{
		output[x] = buffer[y];
		x++;
	}
	output[x] = '\0';
	free (line);
	return (output);
}
