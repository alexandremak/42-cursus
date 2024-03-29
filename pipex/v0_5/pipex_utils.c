/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:25:30 by amak              #+#    #+#             */
/*   Updated: 2023/03/22 21:02:28 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_exit(char *error_msg)
{
	perror(error_msg);
	exit(1);
}

/* FINDS COMMAND DIRECTORIES PATH FROM ENVP */
char	**find_paths(char **envp)
{	
	char	*envp_line;
	char	**paths_array;

	while (ft_strncmp(*envp, "PATH=", 5))
		envp++;
	envp_line = ft_substr(*envp, 5, (ft_strlen(*envp) - 5));
	paths_array = ft_split(envp_line, ':');
	free(envp_line);
	return (paths_array);
}

/* INITS VALUES FOR INFILE, OUTFILE AND COMMANDS DIRECTORY PATHS */
void	init_pipex(char **argv, char **envp, t_pipex *pipex)
{
	pipex->paths = find_paths(envp);
	pipex->infile = open(argv[1], O_RDONLY);
	if (pipex->infile < 0)
		error_exit(argv[1]);
	pipex->outfile = open(argv[4], O_CREAT | O_TRUNC | O_RDWR, 000644);
	if (pipex->outfile < 0)
		error_exit(argv[4]);
}

/*  FREE STRUCTURE PIPEX: closes file discriptor for infile and outfile, 
	command and env paths array  */
void	free_pipex(t_pipex *pipex)
{
	int		i;

	i = 0;
	close(pipex->infile);
	close(pipex->outfile);
	free(pipex->cmd);
	while (pipex->paths[i])
	{
		free(pipex->paths[i]);
		i++;
	}
	free(pipex->paths);
}
