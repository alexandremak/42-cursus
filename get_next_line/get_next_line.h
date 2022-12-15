/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:38:26 by amak              #+#    #+#             */
/*   Updated: 2022/12/15 02:08:29 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 42

# endif

# include <unistd.h>
# include <stdlib.h>

size_t	ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strline(char *str);
char	*get_next_line(int fd);

#endif
