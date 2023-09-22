/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 21:23:27 by amak              #+#    #+#             */
/*   Updated: 2023/09/22 16:06:13 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include "get_next_line.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>

# include <stdio.h>

/* SIZE OF WINDOW AND EACH TILE*/
# define PIXELS 16

/* STRUCTURES */
typedef struct s_map{
	char 	**map_mtrx;
	int		p_xpos;
	int		p_ypos;
	int		e_xpos;
	int		e_ypos;
	int		collects;
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
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *str);

/* VALIDATE MAPFILE */
int		map_ext_ok(char *filepath);
void	check_file(int argc, char **argv, int *fd);

/* VALIDATE AUX */
int		valid_char(char c);
int		load_component(t_map *map, int y, int x);
int		must_contain(t_map *map);

/* VALIDATE MAP DIMENSIONS */
void	load_map(t_map *map, int fd, int count_line);
int 	is_rectangle(t_map *map);
int		wall_ok(t_map *map);
int		valid_components(t_map *map);
void	check_map(int fd, t_map *map);

/* VALIDATE PATH */
char	**mapcpy(t_map *map);
void	flood_fill(char **map, int y, int x);
void	valid_path_exit(t_map *map);

/* MOVING */
int		check_move(t_windows *window, int y, int x);
void	exec_move(t_windows *window, int y, int x);

#endif
