/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:25:30 by amak              #+#    #+#             */
/*   Updated: 2023/03/07 22:50:49 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*path_strg(char **envp)
{
	char	*result;

	while (ft_strncmp(*envp, "PATH=", 5))
		envp++;
	result = ft_substr(*envp, 5, (ft_strlen(*envp) - 5));
	return (result);
}
