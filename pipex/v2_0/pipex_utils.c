/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:25:30 by amak              #+#    #+#             */
/*   Updated: 2023/09/08 02:56:11 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*	Prints a descriptive error message with "perror" function and exits
	process */
void	perror_exit(char *text_msg)
{
	perror(text_msg);
	exit (1);
}

/*	Prints the message in the argument and exits process */
void	write_exit(char *error_msg)
{
	write(2, error_msg, ft_strlen(error_msg));
	write(2, "\n", 1);
	exit (1);
}

/*	Finds and returns the array of directories after the "PATH=" string from
	envp (environment pointer) */
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
	outfile, and directories string array */
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

/*	Closes the pipe created in the struct pipex*/
void	close_pipe(t_pipex *pipex)
{
	close(pipex->pipe_tube[0]);
	close(pipex->pipe_tube[1]);
}
