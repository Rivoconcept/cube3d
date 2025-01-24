/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 13:55:48 by rhanitra          #+#    #+#             */
/*   Updated: 2025/01/23 19:55:40 by rhanitra         ###   ########.fr       */
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
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

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
	t_image				img;
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
	int					move;
	struct s_params		*next;
}						t_params;

void					mlx_initialization(t_params *params);
void					mlx_window_open(t_params *params);
int						handle_keypress(int keycode, t_params *params);
int						handle_mouse_click(t_params *params);

t_map					*put_position_f(t_map *map, char c);
t_line					*create_list_line(char data);
t_map					*create_list_map(t_line *line);
t_params				*create_list_param(void);
t_position				*create_list_position(void);
t_position				*put_position_p(t_map *map, char c);

void					put_ranks_map(t_map **head);
void					put_ranks_line(t_line **head);
int						count_element_list(t_line *head);
int						count_element_list_mapcol(t_map *head);
int						count_element_list_mapline(t_map *head);
int						count_data_game(t_map *map, char c);
int						check_init_road(t_map *map);
int						check_intrus_data(t_map *map);
int						check_rectangle(t_map *map);
int						check_error_wall(t_map *map);
int						check_extension(char *str);
int						check_flood_fill(t_map *map);
char					find_value(t_map *map, t_position *pos);
void					change_value(t_map *map, t_position *pos, char c);
void					move_pass(t_params *params, t_position *pos, int token);
void					initialize_map(t_map **head, t_line *line);
void					initialize_line(t_line **head, char *argv);
t_map	*load_map(char *argv, t_params *params);
void					free_list_position(t_position *head);
void					free_list_map(t_map *head_map);

void					load_img_wall_up_left(t_params *params);
void					load_img_wall_up_center(t_params *params);
void					load_img_wall_up_right(t_params *params);
void					load_img_wall_left(t_params *params);
void					load_img_wall_right(t_params *params);
void					load_img_wall_down_left(t_params *params);
void					load_img_wall_down_center(t_params *params);
void					load_img_wall_down_right(t_params *params);
void					load_img_player(t_params *params);
void					load_img_collectible(t_params *params);
void					load_wall_img(t_params *params);
void					load_img_ground(t_params *params);
void					load_img_exit_close(t_params *params);
void					load_img_exit_open(t_params *params);
void					load_img_you_win(t_params *params);

void					put_wall_up_right(t_params *params);
void					put_wall_up_left(t_params *params);
void					put_wall_up_center(t_params *params);
void					put_wall_down_left(t_params *params);
void					put_wall_down_right(t_params *params);
void					put_wall_down_center(t_params *params);
void					put_wall_left(t_params *params);
void					put_wall_right(t_params *params);
void					put_img_obstacle(t_params *params);
void					put_img_ground(t_params *params);
void					put_img_collectible(t_params *params);
void					put_img_exit(t_params *params);
void					put_img_player(t_params *params);
void					put_img_you_win(t_params *params);

void					put_img_wall(t_params *params);
void					put_img_data(t_params *params);

void	so_long_initializer(char *argv);

void					clean_img_1(t_params *params);
void					clean_img_2(t_params *params);
void					clean_img_3(t_params *params);
void					clean_img_4(t_params *params);
void					clean_img_5(t_params *params);
void					cleanup(t_params *params);


int is_wall_left(t_position *pos, t_map *map);
int is_wall_right(t_position *pos, t_map *map);
int is_wall_up(t_position *pos, t_map *map);
int is_wall_down(t_position *pos, t_map *map);

int	ft_is_space(char c);
int	find_char(char *str, char c);
int	is_only_space(char *str);
int check_error_config(t_params *params);
int is_all_config_set(t_params *params);
#endif
