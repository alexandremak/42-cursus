/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 20:45:22 by amak              #+#    #+#             */
/*   Updated: 2023/09/26 22:36:28 by amak             ###   ########.fr       */
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
	close(file_fd);
	valid_path_exit(&window);
	init_window(&window);
	setup_imgs(&window);
	build_map(&window);
	mlx_key_hook(window.win_ptr, key_press, &window);
	mlx_hook(window.win_ptr, 17, 0, close_window, &window);
	mlx_loop(window.mlx_ptr);
	return (0);
}
