/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 22:13:12 by ttelolah          #+#    #+#             */
/*   Updated: 2025/01/28 18:57:24 by rhanitra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../dependence/gnl/get_next_line.h"
# include "../dependence/libft/libft.h"
# include "../dependence/minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdbool.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <math.h>

# define SCREEN_HEIGHT 			1000
# define SCREEN_WIDTH 			1500

# define ESC 					53
# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3
# define X_EVENT_EXIT			17


# define W 						13
# define A 						0
# define S 						1
# define D 						2
# define UP 					126
# define DOWN 					125
# define LEFT 					123
# define RIGHT 					124

typedef struct s_point
{
	double			x;
	double			y;
}			t_point;



typedef struct s_img
{
	void	*pointer_to_image;
	char	*address;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}				t_img;

typedef struct s_key
{
	int	w;
	int	s;
	int	a;
	int	d;
	int	right;
	int	left;
	int	p;
}		t_key;

/*************************************************************** */

typedef struct s_value
{
	char				value;
	int					index;
}						t_value;

typedef struct s_line
{
	t_value				cell_value;
	struct s_line		*next;
}						t_line;

typedef struct s_content
{
	t_line				*line;
	int					index;
}						t_content;

typedef struct s_map
{
	t_content			line_value;
	struct s_map		*next;
}						t_map;

typedef struct s_adress
{
	int					x;
	int					y;
}						t_adress;

typedef struct s_position
{
	t_adress			value;
	struct s_position	*next;
}						t_position;

typedef struct s_fill
{
	t_position			value;
	struct s_fill		*next;
}						t_fill;

typedef struct s_image
{
	void				*wall_up_left;
	void				*wall_up_center;
	void				*wall_up_right;
	void				*wall_left;
	void				*wall_right;
	void				*wall_down_left;
	void				*wall_down_center;
	void				*wall_down_right;
	void				*flower_one;
	void				*flower_two;
	void				*ground;
	void				*collectible;
	void				*player;
	void				*exit_close;
	void				*exit_open;
	void				*you_win;
}						t_image;

typedef struct s_params
{
	// t_image				img;
	t_map				*map;
	t_position			*pos;
	void				*mlx_connexion;
	void				*win_open;
	char				*no;
	char				*so;
	char				*we;
	char				*ea;
	char				*f;
	char				*c;
	int					x;
	int					y;
	int					win_width;
	int					win_height;
	// int					move;
	struct s_params		*next;
}						t_params;

/************************************************************* */

int	ft_is_space(char c);
int	is_line_map(char *str);
void	free_array(char **arr);
int is_all_config_set(t_params *params);
t_map *load_map(int fd, t_params *params);
int check_error_config(t_params *params);
void	cleanup(t_params *params);



int is_only_space(char *str);
int	perror_msg(char *error, char *var);
void ft_exit_faillure(t_params *params, int fd, char *error, char *var);

int	check_intrus_data(t_map *map);
int	count_data_game(t_map *map, char c);
int	check_extension(char *str);

//r_manage_list_1.c
t_line	*create_list_line(char data);
t_map	*create_list_map(t_line *line);
t_position	*create_list_position(void);
t_params	*create_list_param(void);

//r_manage_list_2.c
int	count_element_list(t_line *head);
int	count_element_list_mapcol(t_map *head);
int	count_element_list_mapline(t_map *head);
void	put_ranks_line(t_line **head);
void	put_ranks_map(t_map **head);

//r_manage_list_3.c
void	free_list_position(t_position *head);
void	free_list_map(t_map *head_map);

//r_utils_1.c
int	ft_is_space(char c);
int	perror_msg(char *error, char *var);
void ft_exit_faillure(t_params *params, int fd, char *error, char *var);
void	free_array(char **arr);
int	find_char(char *str, char c);

//r_utils_2.c
int	is_line_map(char *str);
int is_only_space(char *str);
int is_all_config_set(t_params *params);
int check_error_color(char *color);
int check_error_config(t_params *params);

//r_utils_3.c



//check_error_wall_1.c
int is_wall_left(t_position *pos, t_map *map);
int is_wall_right(t_position *pos, t_map *map);
int is_wall_up(t_position *pos, t_map *map);
int is_wall_down(t_position *pos, t_map *map);

//check_error_wall_2.c
void	go_up(t_map *map, t_position *pos);
void	go_down(t_map *map, t_position *pos);
void	go_left(t_map *map, t_position *pos);
void	go_right(t_map *map, t_position *pos);

//search_function.c
t_position	*put_position_p(t_map *map, char c);
char	find_value(t_map *map, t_position *pos);
void	change_value(t_map *map, t_position *pos, char c);

int	check_wall(t_params *params);

void    print_map(t_params *params);
void    print_line(t_line *line);
void print_config(t_params *params);
#endif