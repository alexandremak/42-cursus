/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:38:26 by amak              #+#    #+#             */
/*   Updated: 2023/01/15 03:00:36 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 42

# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
// # include <sys/types.h>
// # include <sys/stat.h>
// # include <fcntl.h>

size_t	ft_strlen_gnl(char *str);
char	*ft_strjoin_gnl(char *line, char *buffer);
char	*search_line(int flag, char *buffer, int fd);
char	*get_next_line(int fd);

#endif
