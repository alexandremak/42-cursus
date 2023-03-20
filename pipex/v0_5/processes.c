/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 19:40:26 by amak              #+#    #+#             */
/*   Updated: 2023/03/19 21:22:26 by amak             ###   ########.fr       */
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

void	fist_process(t_pipex *pipex, char **argv, char **envp)
{
	printf("infile fd: %d\n", pipex->infile);
	// dup2(pipex->infile, 0);
	// dup2(pipex->tube[1], 1);
	// close(pipex->tube[0]);
	pipex->cmd_flags = ft_split(argv[2], ' ');
	pipex->cmd = pipex->cmd_flags[0];
	pipex->cmd_path = find_cmdpath(pipex->paths, pipex->cmd);
	printf("%s\n", pipex->cmd_path);
	if (*pipex->cmd_path)
		execve(pipex->cmd_path, pipex->cmd_flags, envp);
	else
		printf("command not found: %s\n", pipex->cmd);
}

void	second_process(t_pipex *pipex, char **argv, char **envp)
{
	// printf("outfile fd: %d\n", pipex->outfile);
	dup2(pipex->tube[0], 0);
	close(pipex->tube[1]);
	// dup2(pipex->outfile, 1);
	pipex->cmd_flags = ft_split(argv[3], ' ');
	pipex->cmd = pipex->cmd_flags[0];
	pipex->cmd_path = find_cmdpath(pipex->paths, pipex->cmd);
	printf("-->aqui\n");
	execve(pipex->cmd_path, pipex->cmd_flags, envp);
}
