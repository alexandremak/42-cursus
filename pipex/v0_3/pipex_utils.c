/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:25:30 by amak              #+#    #+#             */
/*   Updated: 2023/03/14 12:37:02 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// t_pipex	*call_pipex()
// {
// 	static t_pipex pipex;
	
// 	return (&pipex);
// }

char	*path_str(char **envp)
{
	char	*result;

	while (ft_strncmp(*envp, "PATH=", 5))
		envp++;
	result = ft_substr(*envp, 5, (ft_strlen(*envp) - 5));
	return (result);
}

char	**find_paths(char **envp, char *cmd)
{	
	char	**paths;
	char	**i;
	char	*output;
	
	output = path_str(envp);
	paths = ft_split(output, ':');
	free(output);
	i = paths;
	while (*i)
	{
		*i = ft_strjoin(*i, "/");
		*i = ft_strjoin(*i, cmd);
		i++;
	}
	return (paths);
}

void	check_file(char *pathfile)
{
	if (access(pathfile, F_OK) < 0)
		printf("No file!");
}
