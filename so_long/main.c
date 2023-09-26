/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 20:45:22 by amak              #+#    #+#             */
/*   Updated: 2023/09/25 23:23:23 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	int	file_fd;
	static t_windows	window;
	// int	i;
	
	// i = 0;
	check_file(argc, argv, &file_fd);
	check_map(file_fd, &window);
	valid_path_exit(&window);
	init_window(&window);
	setup_imgs(&window);
	printf("%d \n", window.map.height);
	printf("%d \n", window.map.width);
	printf("%c", window.map.map_mtrx[1][1]);
	build_map(&window);
	write(1, "-->\n", 4);
	mlx_key_hook(window.win_ptr, key_press, &window);
	mlx_hook(window.win_ptr, 17, 0, close_window, &window);
	mlx_loop(window.mlx_ptr);
	close(file_fd);
	return (0);
}
