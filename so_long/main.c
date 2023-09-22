/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 20:45:22 by amak              #+#    #+#             */
/*   Updated: 2023/09/22 12:34:16 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	int	file_fd;
	static t_windows	windows;
	// int	i;
	
	// i = 0;
	check_file(argc, argv, &file_fd);
	check_map(file_fd, &windows.map);
	valid_path_exit(&windows.map);
	// while (windows.map.map_mtrx[i])
	// {
	// 	printf("%s", windows.map.map_mtrx[i]);
	// 	i++;
	// }
	close(file_fd);
	return (0);
}
