/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:25:30 by amak              #+#    #+#             */
/*   Updated: 2023/03/20 22:34:33 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	static t_pipex	pipex;
	int				id_process_1;
	int				id_process_2;

	if (argc != 5)
		error_exit("Invalid arguments!");
	if (pipe(pipex.tube) < 0)
		printf("Pipe Error!\n");
	init_pipex(argv, envp, &pipex);
	id_process_1 = fork();
	if (id_process_1 == 0)
		first_process(&pipex, argv, envp);
	id_process_2 = fork();
	if (id_process_2 == 0)
		second_process(&pipex, argv, envp);
	close(pipex.tube[0]);
	close(pipex.tube[1]);
	waitpid(id_process_1, 0, 0);
	waitpid(id_process_2, 0, 0);
	free_pipex(&pipex);
	return (0);
}

// valgrind --leak-check=yes ./pipex