/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:25:30 by amak              #+#    #+#             */
/*   Updated: 2023/04/03 23:21:59 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex		pipex;
	int			id_process[2];
	int			i;

	i = 0;
	if (argc != 5)
		error_exit("Not enough arguments!");
	if (pipe(pipex.pipe_tube) < 0)
		error_exit("Error creating pipe!");
	pipex.infile = open(argv[1], O_RDONLY);
	if (pipex.infile < 0)
		error_exit(argv[1]);
	pipex.outfile = open(argv[4], O_CREAT | O_TRUNC | O_RDWR, 000644);
	if (pipex.outfile < 0)
		error_exit(argv[4]);
	pipex.directories = find_directories(envp);
	id_process[0] = fork();
	if (id_process[0] == 0)
	{
		first_process(pipex, argv, envp);
		free_pipex(&pipex);
	}
	id_process[1] = fork();
	if (id_process[1] == 0)
	{
		second_process(pipex, argv, envp);
		free_pipex(&pipex);
	}
	close_pipe(&pipex);
	waitpid(id_process[0], 0, 0);
	write(2, "\n FIRST END \n", 13);
	waitpid(id_process[1], 0, 0);
	write(2, "\n SECOND END \n", 14);
	free_pipex(&pipex);
	return (0);
}

// valgrind --leak-check=full --show-leak-kinds=all ./pipex "/dev/urandom" "alex" "head -1" outfile
