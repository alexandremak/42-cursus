/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:38:32 by amak              #+#    #+#             */
/*   Updated: 2023/01/06 16:39:18 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	char		*result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	while (buffer[0] || read(fd, buffer, BUFFER_SIZE))
	{
		buffer[BUFFER_SIZE] = '\0';
		line = ft_strjoin(line, buffer);
		buffer[0] = '\0';
		if (is_line(line, '\n'))
		{
			result = line_out(line, '\n');
			left_shift(line, buffer, '\n');
			free(line);
			return (result);
		}
	}
	line = ft_strjoin(line, buffer);
	result = ft_strjoin(line, "");
	free (line);
	return (result);
}

int	main(void)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = open("texto.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s", line);
}
