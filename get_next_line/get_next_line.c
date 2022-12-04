/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:38:32 by amak              #+#    #+#             */
/*   Updated: 2022/12/04 18:48:52 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	str[BUFFER_SIZE + 1];
	int		len;

	len = read(fd, str, BUFFER_SIZE)
	str[BUFFER_SIZE + 1] = '\0'; 
}