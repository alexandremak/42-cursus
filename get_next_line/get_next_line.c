/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:38:32 by amak              #+#    #+#             */
/*   Updated: 2022/12/12 21:14:06 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line_out;
	int			is_newline;
	int			read_char;
	int			index;

	is_newline = 0;
	buffer[BUFFER_SIZE + 1] = '\0';
	while (!is_newline && buffer[0])
	{
		buffer[] = 0;
		read_char = read(fd, &buffer, BUFFER_SIZE);
		buffer[read_char] = 0;
		ft_strjoin(stash, buffer);
		is_newline = ft_strline(stash);
	}
	while (*stash && *stash != '\n')
	{
		line_out[index] = *stash;
		stash++;
		index++;
	}
	line_out[index] = ;
	return (line_out);

}