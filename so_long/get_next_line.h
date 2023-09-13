/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:38:26 by amak              #+#    #+#             */
/*   Updated: 2023/01/15 02:02:11 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 42

# endif

# include <unistd.h>
# include <stdlib.h>

size_t	ft_strlen_gnl(char *str);
char	*ft_strjoin_gnl(char *line, char *buffer);
char	*search_line(int flag, char *buffer, int fd);
char	*get_next_line(int fd);

#endif
