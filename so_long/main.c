/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 20:45:22 by amak              #+#    #+#             */
/*   Updated: 2023/10/12 02:52:18 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	int					mapfile_fd;
	static t_windows	window;

	check_file(argc, argv, &mapfile_fd);
	check_map(mapfile_fd, &window);
	check_path(&window);
	init_mlx(&window);
	build_map(&window);
	mlx_key_hook(window.win, key_press, &window);
	mlx_hook(window.win, 17, 0, free_all, &window);
	mlx_loop(window.mlx);
	return (0);
}
