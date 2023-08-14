/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.ma>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 17:38:31 by aben-nei          #+#    #+#             */
/*   Updated: 2023/08/09 18:30:33 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include "libft/libft.h"
# include <fcntl.h>
# include <stdbool.h>
# include <math.h>
# include "get_next_line/get_next_line.h"

# define CUB_SIZE 18
# define SCREEN_WIDTH 1280
# define SCREEN_HEIGHT 720
# define SPEED 2
# define SCALE 32
# define W 13
# define S 1
# define A 0
# define D 2
# define RIGHT 124
# define LEFT 123
# define ESC 53
# define UP 126
# define DOWN 125
# define ROTATE_RIGHT 124
# define ROTATE_LEFT 123
# define NUM_RAYS SCREEN_WIDTH
# define FOV (60 * (M_PI / 180))

typedef struct s_garbage	t_garbage;
typedef struct s_data		t_data;
typedef struct s_dict		t_dict;
typedef struct s_point		t_point;
typedef struct s_mlx		t_mlx;
typedef struct s_flags		t_flags;
typedef struct s_draw		t_draw;

# define MAP_ERROR "Error: something is wrong in the map"

struct s_garbage{
	void		*address;
	t_garbage	*next;
	t_garbage	*last;
};

struct s_dict{
	char	*key;
	char	*value;
	t_dict	*next;
	t_dict	*last;
};

struct s_point {
	double	x;
	double	y;
	double	rotation_angle;
};

struct	s_mlx{
	void	*mlx;
	void	*win;
	int		endian;
	int		line_length;
	int		bits_per_pixel;
	void	*img;
	char	*addr;
};

struct	s_flags{
	int		flag_up;
	int		flag_down;
	int		flag_left;
	int		flag_right;
	int		rotate_right;
	int		rotate_left;
};

struct s_draw{
	double	x;
	double	y;
	double	dx;
	double	dy;
	double	steps;
	double	inc_x;
	double	inc_y;
};

typedef struct s_data {
	t_mlx	mlx;
	t_flags	flags;
	t_draw	draw;
	t_point	player;
	t_dict	*textures;
	double 	angle_vue;
	char	**map;
	int		ceiling[3];
	int		floor[3];
}				t_data;

/*--------------------------- drawing ---------------------------*/
void	drawing_line(t_point *p1, t_point *p2, t_data *data);
void	ft_draw_map(char **map, t_data *data);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	mini_map(t_data *data);
void	get_position_of_player(t_data *data);
void	color_player(t_data *data);
int		key_hook(int code, t_data *data);
void	drawing_rays(t_point *p1, t_point *p2, t_data *data);
void 	casting_rays(t_data *data);
/*--------------------------- utils print ---------------------------*/
void	print(char **map);
void	print_list(t_garbage *garbage);
/*--------------------------- hooks ----------------------------*/
int		key_hook2(int code, t_data *data);
int		key_hook3(t_data *data);

/*-----------------------------cub_utils.c-----------------------------*/
void	throw_error(char *msg, t_garbage **heap);
char	*free_s1_join(char *s1, char *s2);
int		tab_size(char **tab);
int		ft_strcmp(char *s1, char *s2);
bool	is_number(char *str);

/*-----------------------------parsing.c-----------------------------*/
void	check_textures(t_dict *textures, t_garbage **heap);
void	check_rgb_code(int *rgb, t_garbage **heap);
void	check_map_components(char **map, t_garbage **heap);
void	map_is_closed(char **map, t_garbage **heap);
void	space_checker(char **map, t_garbage **heap);

/*-----------------------------map_reader.c-----------------------------*/
char	**get_full_map(char *path, t_garbage **heap);

/*-----------------------------g_collector.c-----------------------------*/
void	add_to_garbage(t_garbage **heap, void *address);
void	empty_trash(t_garbage **heap);

/*-----------------------------dict_utils.c-----------------------------*/
char	*get_key_value(char *str, short option, t_garbage **heap);

/*-----------------------------initializer.c-----------------------------*/
void	init_data(t_data *data, char **full_map, t_garbage **heap);

/*-----------------------------parsing_utils.c-----------------------------*/
bool	is_valid_component(char c);
void	skip_spaces(char *line, int *i);

#endif