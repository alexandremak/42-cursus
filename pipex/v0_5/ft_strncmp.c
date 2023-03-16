/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 22:21:23 by amak              #+#    #+#             */
/*   Updated: 2023/03/07 22:21:29 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	pos;

	pos = 0;
	while (pos < n && (s1[pos] != '\0' || s2[pos] != '\0'))
	{
		if (s1[pos] != s2[pos])
			return (((unsigned char *)s1)[pos] - ((unsigned char *)s2)[pos]);
		pos++;
	}
	return (0);
}

// return cast to unsigned char because the string/char can have values beyond
// char limits from -128 to 127 used like /200.