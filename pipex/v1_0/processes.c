/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 19:40:26 by amak              #+#    #+#             */
/*   Updated: 2023/03/24 22:58:29 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* 	Check if the command exists with "access" function after joining the
	directories with "/cmd" and returns the full path if exists or
	return NULL if does not	*/
char	*find_cmdpath(char **directories, char *cmd)
{
	char	*output;

	while (*directories)
	{
		output = ft_strjoin(*directories, "/");
		output = ft_strjoin(output, cmd);
		if (access(output, F_OK) == 0)
			return (output);
		directories++;
	}
	free(output);
	return (NULL);
}

/*	Free variables from struct pipex: array of command flags, path
 	and command */
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

/*	First child process: redirects the file descriptor: STDIN to infile and
	STDOUT to pipe[1] (write), closes pipe[0] (read), splits command and flags
	to an array, executes the command. If "execve" executes it terminates the
	process, else (because the command path is NULL) it prompts the command not
	found error and frees the variables of struct pipex that was used and exit
	the process */
void	first_process(t_pipex pipex, char **argv, char **envp)
{
	dup2(pipex.infile, STDIN_FILENO);
	dup2(pipex.pipe_tube[1], STDOUT_FILENO);
	close(pipex.pipe_tube[0]);
	pipex.cmd_flags = ft_split(argv[2], ' ');
	pipex.cmd = ft_strdup(pipex.cmd_flags[0]);
	pipex.cmd_path = find_cmdpath(pipex.directories, pipex.cmd);
	if (execve(pipex.cmd_path, pipex.cmd_flags, envp))
	{
		write(2, pipex.cmd, ft_strlen(pipex.cmd));
		write(2, ": command not found\n", 20);
		free_process(&pipex);
		exit(1);
	}
}

/*	Second child process: redirects file descriptor: STDIN to pipe[0] (read)
	that and STDOUT to outfile, closes pipe[1] (write), splits command and flags
	to an array, executes the command. If "execve" executes it terminates the
	process, else (because the command path is NULL) it prompts command not
	found error and frees the variables of struct pipex that was used and exit
	the process */
void	second_process(t_pipex pipex, char **argv, char **envp)
{
	dup2(pipex.pipe_tube[0], 0);
	dup2(pipex.outfile, 1);
	close(pipex.pipe_tube[1]);
	pipex.cmd_flags = ft_split(argv[3], ' ');
	pipex.cmd = ft_strdup(pipex.cmd_flags[0]);
	pipex.cmd_path = find_cmdpath(pipex.directories, pipex.cmd);
	if (execve(pipex.cmd_path, pipex.cmd_flags, envp))
	{
		write(2, pipex.cmd, ft_strlen(pipex.cmd));
		write(2, ": command not found\n", 20);
		free_process(&pipex);
		exit(1);
	}
}
