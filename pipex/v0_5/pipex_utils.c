/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:25:30 by amak              #+#    #+#             */
/*   Updated: 2023/03/16 22:06:06 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**find_paths(char **envp)
{	
	char	*envp_line;
	char	**paths_array;

	while (ft_strncmp(*envp, "PATH=", 5))
		envp++;
	envp_line = ft_substr(*envp, 5, (ft_strlen(*envp) - 5));
	// printf("%s\n", envp_line);
	paths_array = ft_split(envp_line, ':');
	free(envp_line);
	return (paths_array);
}
