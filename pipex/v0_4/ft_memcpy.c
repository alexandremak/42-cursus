/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 21:42:31 by amak              #+#    #+#             */
/*   Updated: 2023/03/07 19:52:30 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	pos;

	pos = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (pos < n)
	{
		((char *)dest)[pos] = ((char *)src)[pos];
		pos++;
	}
	return (dest);
}
