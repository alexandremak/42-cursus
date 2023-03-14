/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:25:30 by amak              #+#    #+#             */
/*   Updated: 2023/03/14 22:02:13 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc != 5)
		printf("wrong arguments!\n");
	else
	{
		pipex.infile = argv[1];
		check_file(pipex.infile);
		printf("Infile: %s\n", pipex.infile);
		pipex.outfile = argv[4];
		printf("Outfile: %s\n", pipex.outfile);
		pipex.cmd_flags1 = ft_split(argv[2], ' ');
		pipex.cmd_flags2 = ft_split(argv[3], ' ');
		printf("----->\n");
		pipex.cmd_path1 = find_pathfile(envp, pipex.cmd_flags1[0]);
		printf("Pathfile 1: %s\n", pipex.cmd_path1);
		pipex.cmd_path2 = find_pathfile(envp, pipex.cmd_flags2[0]);
		printf("Pathfile 2: %s\n", pipex.cmd_path2);
	}
}


// gcc -Wall -Wextra -Werror pipex.c pipex_utils.c ft_calloc.c ft_memcpy.c ft_putstr.c ft_split.c ft_strdup.c ft_strjoin.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_substr.c -o pipex