/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:25:30 by amak              #+#    #+#             */
/*   Updated: 2023/03/14 13:50:24 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex pipex;
	
	if (argc != 5)
		printf("wrong arguments!\n");
	else
	{
		pipex.infile = argv[1];
		check_file(pipex.infile);
		pipex.cmd1 = argv[2];
		pipex.cmd2 = argv[3];
		pipex.outfile = argv[4];
		pipex.paths1 = find_paths(envp, pipex.cmd1);
		pipex.paths2 = find_paths(envp, pipex.cmd2);
		while (*pipex.paths1)
		{
			printf("%s", *pipex.paths1);
			execve(*pipex.paths1, *pipex.infile, envp);
			pipex.paths1++;
		}
	}
}


// gcc -Wall -Wextra -Werror pipex.c pipex_utils.c ft_calloc.c ft_memcpy.c ft_putstr.c ft_split.c ft_strdup.c ft_strjoin.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_substr.c -o pipex