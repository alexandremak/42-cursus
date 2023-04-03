/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:25:30 by amak              #+#    #+#             */
/*   Updated: 2023/04/03 22:43:34 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*	Shows error with "perror" function and exits process */
void	error_exit(char *error_msg)
{
	perror(error_msg);
	exit (1);
}

/*	Finds and returns array of directories from "PATH=" string from envp */
char	**find_directories(char **envp)
{	
	char	*envp_line;
	char	**dir_array;

	while (ft_strncmp(*envp, "PATH=", 5))
		envp++;
	envp_line = ft_substr(*envp, 5, (ft_strlen(*envp) - 5));
	dir_array = ft_split(envp_line, ':');
	free(envp_line);
	return (dir_array);
}

/*	Free variables from struct pipex: closes file discriptor for infile,
	outfile, and directories array */
void	free_pipex(t_pipex *pipex)
{
	int		i;

	i = 0;
	close(pipex->infile);
	close(pipex->outfile);
	while (pipex->directories[i])
	{
		free(pipex->directories[i]);
		i++;
	}
	free(pipex->directories);
}

/*	Closes pipe array variable from struct pipex */
void	close_pipe(t_pipex *pipex)
{
	close(pipex->pipe_tube[0]);
	close(pipex->pipe_tube[1]);
}
