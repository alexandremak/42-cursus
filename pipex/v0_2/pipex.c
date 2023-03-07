/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 16:25:30 by amak              #+#    #+#             */
/*   Updated: 2023/03/07 22:49:59 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	char	*output;
	char	**paths;

	if (argc != 5)
		printf("wrong arguments!\n");
	printf("%s\n", argv[0]);
	output = path_strg(envp);
	printf("%s\n", output);
	paths = ft_split(output, ':');
	while (*paths)
	{
		printf("%s\n", *paths);
		paths++;
	}
}


// gcc -Wall -Wextra -Werror pipex.c pipex_utils.c ft_calloc.c ft_memcpy.c ft_putstr.c ft_split.c ft_strdup.c ft_strjoin.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_substr.c -o pipex