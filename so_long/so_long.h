/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 21:23:27 by amak              #+#    #+#             */
/*   Updated: 2023/10/12 22:20:27 by amak             ###   ########.fr       */
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

/* KEYBOARD CODES*/
# define ESC 65307

# define W 119
# define S 115
# define A 97
# define D 100

/* SIZE OF WINDOW AND EACH TILE*/
# define PX 32

/* STRUCTURES */
typedef struct s_map{
	char	**mtrx;
	int		ply_x;
	int		ply_y;
	char	last_key;
	int		ext_x;
	int		ext_y;
	int		collects;
	int		width;
	int		height;
	int		moves;
}	t_map;

typedef struct s_images{
	void	*cltb;
	void	*e;
	void	*eo;
	void	*ps;
	void	*pw;
	void	*pa;
	void	*pd;
	void	*space;
	void	*wall;
	void	*pe;
}	t_images;

typedef struct s_windows{
	void		*mlx;
	void		*win;
	t_map		map;
	t_images	img;
}	t_windows;

/* LIBFT UTILITIES */
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *str);

/* CHECK MAPFILE */
int		map_ext_ok(char *filepath);
void	check_file(int argc, char **argv, int *fd);

/* CHECK AUX */
int		valid_char(char c);
int		load_component(t_windows *window, int y, int x);
int		must_contain(t_windows *window);

/* CHECK MAP DIMENSIONS */
void	load_map(t_windows *window, int fd, int count_line);
int		is_rectangle(t_windows *window);
int		wall_ok(t_map *map);
int		valid_components(t_windows *window);
void	check_map(int fd, t_windows *window);

/* CHECK PATH */
char	**mapcpy(t_windows *window);
void	flood_fill(char **map, int y, int x);
void	check_path(t_windows *window);

/* MLX WINDOW*/
void	init_imgs(t_windows *window);
void	init_mlx(t_windows *window);
int		key_press(int keycode, t_windows *window);

/* MAP BUILDER */
void	insert_player_img(int y, int x, t_windows *w);
void	insert_img(char c, int y, int x, t_windows *w);
void	build_map(t_windows *window);

/* MOVING */
void	put_posnbr(int n);
int		check_move(t_windows *window, int y, int x);
void	exec_move(t_windows *window, int y, int x);
void	move(t_windows *window, int y, int x);

/* EXIT FUNCTIONS*/
void	free_map(char **map);
void	free_imgs(t_windows *window);
void	close_window(t_windows *window);

#endif
