/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 19:40:26 by amak              #+#    #+#             */
/*   Updated: 2023/03/20 22:10:19 by amak             ###   ########.fr       */
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
		if (access(output, F_OK) == 0)
			return (output);
		paths++;
	}
	free(output);
	return (NULL);
}

void	free_process(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (pipex->cmd_flags[i])
	{
		free(pipex->cmd_flags[i]);
		i++;
	}
	free (pipex->cmd_flags);
	free (pipex->cmd_path);
	free (pipex->cmd);
}

void	first_process(t_pipex *pipex, char **argv, char **envp)
{
	dup2(pipex->infile, 0);
	dup2(pipex->tube[1], 1);
	close(pipex->tube[0]);
	pipex->cmd_flags = ft_split(argv[2], ' ');
	pipex->cmd = pipex->cmd_flags[0];
	pipex->cmd_path = find_cmdpath(pipex->paths, pipex->cmd);
	if (*pipex->cmd_path)
		execve(pipex->cmd_path, pipex->cmd_flags, envp);
	else
	{
		free_process(pipex);
		error_exit("command not found");
	}
}

void	second_process(t_pipex *pipex, char **argv, char **envp)
{
	dup2(pipex->tube[0], 0);
	close(pipex->tube[1]);
	dup2(pipex->outfile, 1);
	pipex->cmd_flags = ft_split(argv[3], ' ');
	pipex->cmd = pipex->cmd_flags[0];
	pipex->cmd_path = find_cmdpath(pipex->paths, pipex->cmd);
	if (*pipex->cmd_path)
		execve(pipex->cmd_path, pipex->cmd_flags, envp);
	else
	{
		free_process(pipex);
		error_exit("command not found");
	}
}
