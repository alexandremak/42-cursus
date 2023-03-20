/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:25:30 by amak              #+#    #+#             */
/*   Updated: 2023/03/19 22:38:35 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	int		id_process_1;
	int		id_process_2;

	if (argc != 5)
	{
		printf("wrong arguments!\n");
		return (0);
	}
	if (pipe(pipex.tube) < 0)
		printf("Pipe Error!\n");
	if (init_pipex(argv, envp, &pipex))
	{
		id_process_1 = fork();
		// printf("process ID first fork: %d\n", id_process_1);
		if (id_process_1 == 0)
		{
			write(1, "A\n", 2);
			fist_process(&pipex, argv, envp);
		}
		else
		{
			waitpid(id_process_1, 0, 0);
			id_process_2 = fork();
			// printf("process ID second fork: %d\n", id_process_2);
			if (id_process_2 == 0)
			{
				write(1, "B\n", 2);
				second_process(&pipex, argv, envp);
			}
			else
				waitpid(id_process_2, 0, 0);	
		}
	}
	close(pipex.tube[0]);
	close(pipex.tube[1]);
	return(0)
}

// gcc -Wall -Wextra -Werror pipex.c pipex_utils.c ft_calloc.c ft_memcpy.c ft_putstr.c ft_split.c ft_strdup.c ft_strjoin.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_substr.c processes.c -o pipex
// valgrind --leak-check=yes ./pipex