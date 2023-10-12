/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 22:57:27 by amak              #+#    #+#             */
/*   Updated: 2023/10/12 22:53:10 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*	Check if the map file is an .ber extension file */
int	map_ext_ok(char *filepath)
{
	int	size;

	size = ft_strlen(filepath);
	if (size >= 5)
		if (filepath[size - 1] == 'r')
			if (filepath[size - 2] == 'e')
				if (filepath[size - 3] == 'b')
					if (filepath[size - 4] == '.')
						return (1);
	return (0);
}

/* Checks if the program parameter is a valid map file */
void	check_file(int argc, char **argv, int *fd)
{
	if (argc == 1)
	{
		write(2, "Error: No map file as parameter!\n", 33);
		exit(1);
	}
	if (argc > 2)
	{
		write(2, "Error: Too many parameters inserted!\n", 37);
		exit(1);
	}
	if (!map_ext_ok(argv[1]))
	{
		write(2, "Error: Map is not a *.ber file!\n", 32);
		exit(1);
	}
	*fd = open(argv[1], O_RDONLY);
	if (*fd < 0)
	{
		write(2, "Error: Map file doesn't exists!\n", 32);
		exit(1);
	}
}
