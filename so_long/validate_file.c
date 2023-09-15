/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 22:57:27 by amak              #+#    #+#             */
/*   Updated: 2023/09/15 19:18:39 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	check_file(int argc, char **argv)
{
	if (argc == 1)
	{
		write(2, "Error: No map file as parameter!\n", 33);
		exit(1);
	}
	if (!map_ext_ok(argv[1]))
	{
		write(2, "Error: Map is not a *.ber file!\n", 32);
		exit(1);
	}
}

int	open_file(char *pathfile)
{
	int	map_fd;

	map_fd = open(pathfile, O_RDONLY);
	if (map_fd < 0)
	{
		write(2, "Error: Map file doesn't exists!\n", 32);
		exit(1);
	}
	else
		return (map_fd);
}
