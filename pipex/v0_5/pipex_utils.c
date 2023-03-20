/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:25:30 by amak              #+#    #+#             */
/*   Updated: 2023/03/19 20:14:11 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* PRINTS NO FILE OR DIRECTORY ERROR */
void	file_error(char *filename)
{
	write(1, filename, ft_strlen(filename));
	write(1, ": No such file or directory\n", 28);
}

/* FINDS COMMAND DIRECTORIES PATH FROM ENVP */
char	**find_paths(char **envp)
{	
	char	*envp_line;
	char	**paths_array;

	while (ft_strncmp(*envp, "PATH=", 5))
		envp++;
	envp_line = ft_substr(*envp, 5, (ft_strlen(*envp) - 5));
	// printf("%s\n", envp_line);
	paths_array = ft_split(envp_line, ':');
	free(envp_line);
	return (paths_array);
}

/* INITS VALUES FOR INFILE, OUTFILE AND COMMANDS DIRECTORY PATHS */
int		init_pipex(char **argv, char **envp, t_pipex *pipex)
{
	pipex->paths = find_paths(envp);
	if (access(argv[1], F_OK) == 0)
		pipex->infile = open(argv[1], O_RDONLY);
	else
	{
		file_error(argv[1]);
		return (0);
	}
	pipex->outfile = open(argv[4], O_CREAT | O_TRUNC | O_RDWR, 000644);
	pipex->paths = find_paths(envp);
	return (1);
}
