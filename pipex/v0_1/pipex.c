/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:25:30 by amak              #+#    #+#             */
/*   Updated: 2023/03/04 17:56:27 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char **first_cmd;
char **second_cmd;

int	main(int argc, char **argv)
{
	if (argc != 5)
		write(1, "Invalid arguments!\n", 20);
	else
	{
		
		if (open(argv[1], O_RDONLY) < 0)
		{	
			write(1, "no such file or directory: ", 27);
			ft_putstr(argv[1]);
			write(1, "\n", 1);
		}
		if (open(argv[4], O_RDONLY) < 0)
		{	
			write(1, "no such file or directory: ", 27);
			ft_putstr(argv[4]);
			write(1, "\n", 1);
		}
		first_cmd = ft_split(argv[2], ' ');
		second_cmd = ft_split(argv[3], ' ');
		if (execve(first_cmd[0], first_cmd, NULL) < 0)
		{	
			ft_putstr(first_cmd[0]);
			write(1, ": command not found\n", 20);
		}
		if (execve(second_cmd[0], second_cmd, NULL) < 0)
		{	
			ft_putstr(second_cmd[0]);
			write(1, ": command not found\n", 20);
		}
	}
	return (1);
}


// gcc -Wall -Wextra -Werror pipex.c ft_calloc.c ft_putstr.c ft_split.c ft_strlcpy.c ft_strlen.c -o pipex