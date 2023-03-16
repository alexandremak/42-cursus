/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 18:39:25 by amak              #+#    #+#             */
/*   Updated: 2023/03/15 14:49:09 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "pipex.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*result;
	size_t	pos1;
	size_t	pos2;

	result = (char *)malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
	pos1 = 0;
	pos2 = 0;
	if (result == NULL)
		return (NULL);
	if (ft_strlen((char *)s1) > 0)
	{
		ft_memcpy(result, s1, ft_strlen((char *)s1));
		pos1 = ft_strlen((char *)s1);
	}
	if (ft_strlen((char *)s2) > 0)
	{
		while (s2[pos2] != '\0')
		{
			result[pos1 + pos2] = s2[pos2];
			pos2++;
		}
	}
	result[pos1 + pos2] = '\0';
	return (result);
}
