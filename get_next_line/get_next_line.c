/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:38:32 by amak              #+#    #+#             */
/*   Updated: 2022/12/15 02:13:15 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	size_t		index;
	char		*result;
	size_t		res_i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	while (buffer[0] || read(fd, &buffer, BUFFER_SIZE))
	{
		line = ft_strjoin(line, buffer);
		buffer[0] = '\0';
		index = 0;
		result = 0;
		while (index < ft_strlen(line))
		{
			if (line[index] != '\n')
				index++;
			else
			{
				result = (char *)malloc(sizeof(char) * (index + 1));
				if (!result)
					return (NULL);
				result[index + 1] = '\0';
				res_i = 0;
				while (res_i <= index)
				{
					result[res_i] = line[res_i];
					res_i++;
				}
				res_i = 0;
				while (index < ft_strlen(line))
				{
					buffer[res_i] = line[index];
					res_i++;
					index++;
				}
				return (result);
			}
		}
	}
	return (result);
}
