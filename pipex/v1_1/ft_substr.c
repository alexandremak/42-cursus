/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 19:42:48 by amak              #+#    #+#             */
/*   Updated: 2023/03/20 19:41:06 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*temp;
	size_t	pos;

	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (len > ft_strlen(&s[start]))
		len = ft_strlen(&s[start]);
	temp = (char *)malloc((sizeof(char) * len) + 1);
	pos = 0;
	if (temp == NULL)
		return (NULL);
	while (pos < len)
	{
		temp[pos] = s[start + pos];
		pos++;
	}
	temp[pos] = '\0';
	return (temp);
}
