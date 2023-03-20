/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:25:30 by amak              #+#    #+#             */
/*   Updated: 2023/03/20 22:13:49 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* PRINTS: NO FILE OR DIRECTORY ERROR */
void	file_error(char *filename)
{
	write(1, filename, ft_strlen(filename));
	write(1, ": No such file or directory\n", 28);
}

void	error_exit(char *error_msg)
{
	ft_putstr(error_msg);
	write(1, "\n", 1);
	exit(0);
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
	if (access(argv[1], F_OK) == 0)
	{
		pipex->infile = open(argv[1], O_RDONLY);
		pipex->outfile = open(argv[4], O_CREAT | O_TRUNC | O_RDWR, 000644);
	}
	else
		file_error(argv[1]);
}

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
