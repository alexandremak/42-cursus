/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 19:40:26 by amak              #+#    #+#             */
/*   Updated: 2023/03/17 00:09:36 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_cmdpath(char **paths, char *cmd)
{
	char	*output;

	while (*paths)
	{
		output = ft_strjoin(*paths, "/");
		output = ft_strjoin(output, cmd);
		// printf("%s\n", output);
		if (access(output, F_OK) == 0)
			return (output);
		paths++;
	}
	free(output);
	return (NULL);
}

void	fist_process(t_pipex *pipex, char **argv, char **envp)
{
	// int	teste;

	pipex->cmd_flags = ft_split(argv[2], ' ');
	// while (*pipex->cmd_flags)
	// {
	// 	printf("%s\n", *pipex->cmd_flags);
	// 	pipex->cmd_flags++;
	// }
	pipex->cmd = pipex->cmd_flags[0];
	// printf("comand: %s\n", pipex->cmd);
	pipex->cmd_path = find_cmdpath(pipex->paths, pipex->cmd);
	// printf("path: %s\n", pipex->cmd_path);
	execve(pipex->cmd_path, pipex->cmd_flags, envp);
	// printf("%d", teste);
}

void	second_process(t_pipex *pipex, char **argv, char **envp)
{
	pipex->cmd_flags = ft_split(argv[3], ' ');
	pipex->cmd = pipex->cmd_flags[0];
	pipex->cmd_path = find_cmdpath(pipex->paths, pipex->cmd);
	execve(pipex->cmd_path, pipex->cmd_flags, envp);
}
