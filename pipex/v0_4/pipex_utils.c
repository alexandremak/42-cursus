/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:25:30 by amak              #+#    #+#             */
/*   Updated: 2023/03/14 21:57:33 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_file(char *pathfile)
{
	if (access(pathfile, F_OK) < 0)
		printf("No file!\n");
}

char	*find_path_line(char **envp)
{
	char	*result;

	while (ft_strncmp(*envp, "PATH=", 5))
		envp++;
	result = ft_substr(*envp, 5, (ft_strlen(*envp) - 5));
	return (result);
}

char	*find_pathfile(char **envp, char *cmd)
{
	char	*envp_path;
	char	**paths;
	char	*output;

	envp_path = find_path_line(envp);
	paths = ft_split(envp_path, ':');
	while (*paths)
	{
		*paths = ft_strjoin(*paths, "/");
		*paths = ft_strjoin(*paths, cmd);
		if (access(*paths, F_OK) == 0)
		{
			output = ft_calloc(ft_strlen(*paths), sizeof(char));
			output = *paths;
			break ;
		}
		else
			paths++;
	}
	free(envp_path);
	free(paths);
	return (output);
}
