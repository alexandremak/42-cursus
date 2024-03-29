/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 19:40:26 by amak              #+#    #+#             */
/*   Updated: 2023/03/22 22:39:15 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* 	Check if command exists with "access" function joining the paths with "/cmd"
	and returns the full path if exists or return NULL if does not	*/
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

/*	Free structure pipex command flags, path and command  */	
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

/*	First child process: duplicating file descriptor: STD_IN to infile, STD_OUT 
	to pipe[1 - OUT] and closing pipe[0 - IN], find 1st command flags and path 
	then if not void executes command, else frees structure pipex and prompt error and exit process  */	
void	first_process(t_pipex *pipex, char **argv, char **envp)
{
	dup2(pipex->infile, 0);
	dup2(pipex->tube[1], 1);
	close(pipex->tube[0]);
	pipex->cmd_flags = ft_split(argv[2], ' ');
	pipex->cmd = pipex->cmd_flags[0];
	pipex->cmd_path = find_cmdpath(pipex->paths, pipex->cmd);
	if (!pipex->cmd_path)
	{
		free_process(pipex);
		perror("command not found");
		exit(1);
	}
	execve(pipex->cmd_path, pipex->cmd_flags, envp);
}

/*	Second child process: duplicating file descriptor: STD_OUT to pipe[0 - OUT],
	STD_OUT to outfile and closing pipe[1 - OUT], find 2nd command flags and path 
	then if not void executes command, else frees structure pipex and prompt error and exit process  */	
void	second_process(t_pipex *pipex, char **argv, char **envp)
{
	dup2(pipex->tube[0], 0);
	dup2(pipex->outfile, 1);
	close(pipex->tube[1]);
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
