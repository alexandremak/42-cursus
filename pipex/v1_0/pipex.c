/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:25:30 by amak              #+#    #+#             */
/*   Updated: 2023/03/30 23:28:57 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	static t_pipex	pipex;
	int				id_process[2];

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
		first_process(pipex, argv, envp);
	id_process[1] = fork();
	if (id_process[1] == 0)
		second_process(pipex, argv, envp);
	close_pipe(&pipex);
	waitpid(id_process[0], 0, 0);
	waitpid(id_process[1], 0, 0);
	free_pipex(&pipex);
	return (0);
}

// valgrind --leak-check=yes ./pipex