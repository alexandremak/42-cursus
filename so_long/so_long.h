/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 21:23:27 by amak              #+#    #+#             */
/*   Updated: 2023/10/11 20:42:10 by amak             ###   ########.fr       */
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

/* KEYBOARD CODES*/
# define ESC 65307

# define W 119
# define S 115
# define A 97
# define D 100

/* SIZE OF WINDOW AND EACH TILE*/
# define PIXELS 32

/* STRUCTURES */
typedef struct s_map{
	char	**mtrx;
	int		p_xpos;
	int		p_ypos;
	char	last_key;
	int		e_xpos;
	int		e_ypos;
	int		collects;
	int		width;
	int		height;
	int		count_moves;
}	t_map;

typedef struct s_images{
	void	*collect;
	void	*exit;
	void	*exit_open;
	void	*player_s;
	void	*player_w;
	void	*player_a;
	void	*player_d;
	void	*space;
	void	*wall;
	void	*player_exit;
}	t_images;

typedef struct s_windows{
	void		*mlx_ptr;
	void		*win_ptr;
	t_map		map;
	t_images	images;
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
int		wall_ok(t_windows *window);
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
void	insert_img(char c, int y, int x, t_windows *window);
void	build_map(t_windows *window);

/* MOVING */
void	put_posnbr(int n);
int		check_move(t_windows *window, int y, int x);
void	exec_move(t_windows *window, int y, int x);
void	move(t_windows *window, int y, int x);

/* EXIT FUNCTIONS*/
void	free_map(char **map);
void	free_imgs(t_windows *window);
int		free_all(t_windows *window);
void	close_window(t_windows *window);

#endif
