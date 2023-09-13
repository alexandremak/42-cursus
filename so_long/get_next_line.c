/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:38:32 by amak              #+#    #+#             */
/*   Updated: 2023/01/15 06:38:42 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*search_line(int flag, char *buffer, int fd)
{
	char	*line;
	int		x;
	int		y;

	line = NULL;
	while (!flag && (buffer[0] || read(fd, buffer, BUFFER_SIZE)))
	{
		x = 0;
		y = 0;
		line = ft_strjoin_gnl(line, buffer);
		while (buffer[x])
		{
			if (flag)
			{
				buffer[y] = buffer[x];
				y++;
			}
			if (buffer[x] == '\n')
				flag = 1;
			buffer[x] = '\0';
			x++;
		}
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			flag;
	int			i;

	line = NULL;
	flag = 0;
	i = 0;
	if ((read(fd, 0, 0) < 0) || BUFFER_SIZE < 1)
	{
		while (buffer[i])
		{
			buffer[i] = '\0';
			i++;
		}
		return (NULL);
	}
	line = search_line(flag, buffer, fd);
	return (line);
}
