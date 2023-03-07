/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 22:13:25 by amak              #+#    #+#             */
/*   Updated: 2023/02/28 22:16:26 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	pos;
	size_t	result;

	pos = 0;
	result = ft_strlen((char *)src);
	if (size != 0)
	{
		while (src[pos] != '\0' && pos < (size - 1))
		{
			dst[pos] = src[pos];
			pos++;
		}
		dst[pos] = '\0';
	}
	return (result);
}
