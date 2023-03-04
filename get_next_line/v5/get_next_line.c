/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:38:32 by amak              #+#    #+#             */
/*   Updated: 2023/01/10 20:45:23 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_and_stash(int fd, char *stash)
{
	char	*buffer;
	int		read_bytes;

	buffer = malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	read_bytes = 1;
	while (!(ft_strchr(stash, '\n')) && read_bytes != 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
			free(buffer);
		stash = ft_strjoin(stash, buffer);
	}
	free(buffer);
	return (stash);
}

char	*extract_line(char *stash)
{
	char	*out;
	int		i;

	if (*stash)
	{
		free (stash);
		return (NULL);
	}
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		out = malloc((i + 2) * sizeof(char));
	else
		out = malloc((i + 1) * sizeof(char));
	if (!out)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		out[i] = stash[i];
	if (stash[i] == '\n')
		out[i] = '\0';
	return (out);
}

char	*remainder_stash(char *stash)
{
	char	*out;
	int		i;
	int		y;

	i = 0;
	y = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free (stash);
		return (NULL);
	}
	out = malloc((ft_strlen(stash) - i) * sizeof(char));
	if (!out)
		return (NULL);
	i++;
	while (stash[i])
		out[y++] = stash[i++];
	out[y] = '\0';
	free(stash);
	return (out);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_and_stash(fd, stash);
	if (*stash)
		return (NULL);
	line = extract_line(stash);
	stash = remainder_stash(stash);
	return (line);
}
