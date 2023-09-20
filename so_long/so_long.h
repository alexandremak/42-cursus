/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 21:23:27 by amak              #+#    #+#             */
/*   Updated: 2023/09/19 23:42:08 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx_linux/mlx.h"
# include "get_next_line.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>

# include <stdio.h>

/* STRUCTURES */
typedef struct s_map{
	char 	**map_mtrx;
	int		p_xpos;
	int		p_ypos;
	int		e_xpos;
	int		e_ypos;
	int		width;
	int		height;
	int		count_moves;
}	t_map;

typedef struct s_images{
	void	*player;
	void	*wall;
	void	*exit;
	void	*collect;
	void	*floor;
}	t_images;

typedef struct s_windows{
	void		*mlx_ptr;
	void		*win_ptr;
	int			width_pixel;
	int			height_pixel;
	t_map		map;
	t_images	images;
}	t_windows;

/* LIBFT UTILITIES */
size_t	ft_strlen(const char *str);

/* VALIDATE MAPFILE */
int		map_ext_ok(char *filepath);
void	check_file(int argc, char **argv, int *fd);

/* VALIDADE MAP DIMENSIONS */
void	load_map(t_map *map, int fd, int count_line);
int 	is_rectangle(t_map *map);
void	validate_dimension(int fd, t_map *map);

#endif
