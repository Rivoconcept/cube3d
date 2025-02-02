/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 22:13:12 by ttelolah          #+#    #+#             */
/*   Updated: 2025/02/02 15:02:09 by rhanitra         ###   ########.fr       */
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

#define RED_PIXEL 0xFF0000

# define SCREEN_WIDTH 			1024
# define SCREEN_HEIGHT 			720

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

//position of map_value
typedef struct s_position
{
	t_adress			value;
	struct s_position	*next;
}						t_position;

//ground_color
typedef struct s_f
{
    int	r;
    int	g;
    int b;
}	t_f;

//ceiling_color
typedef struct s_c
{
    int	r;
    int	g;
    int b;
}	t_c;

//rectangle_form
typedef struct s_player
{
    int	x;
    int	y;
    int width;
    int height;
    int color;
}	t_player;

typedef struct s_rect
{
    int	x;
    int	y;
    int width;
    int height;
    int color;
}	t_rect;

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
	t_f					*f_color;
	t_c					*c_color;
	t_rect				*rect;
	t_player			*player;
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
t_f	*init_ground_color(void);
t_c	*init_ceiling_color(void);

//r_manage_list_2.c
int	count_element_list(t_line *head);
int	count_element_list_mapcol(t_map *head);
int	count_element_list_mapline(t_map *head);
void	put_ranks_line(t_line **head);
void	put_ranks_map(t_map **head);

//r_manage_list_3.c
void	free_list_position(t_position *head);
void	free_list_map(t_map *head_map);
t_params	*create_list_param(void);

//r_render_1.c
int	encode_color(uint8_t r, uint8_t g, uint8_t b);
int	pixel_render(t_params *params);

//r_render_2.c




//r_utils_1.c
int	ft_is_space(char c);
int	perror_msg(char *error, char *var);
void ft_exit_faillure(t_params *params, int fd, char *error, char *var);
void	free_array(char **arr);
int	find_char(char *str, char c);

//r_utils_2.c
int is_only_space(char *str);
int is_all_config_set(t_params *params);
int check_error_color(char *color, t_params *params);
int check_error_config(t_params *params);

//r_utils_3.c

//check_error_1.c
int is_not_playable(char c, t_position *pos, t_map *map);

//check_error_2.c
int	check_map(t_params *params);

//check_error_3.c
int	check_error(int fd, t_params *params);

//r_cleanup.c
void	cleanup(t_params *params);

//r_handle_window.c
int	handle_keypress(int keycode, t_params *params);
int	handle_mouse_click(t_params *params);

//r_init_game_1.c
void	initialize_line(t_line **head, char *gnl);
void	initialize_map(t_map **head, t_line *line);
char	*copy_config(char *gnl, int *i);
int in_base(char *gnl);
int put_data_config(t_params *params, char *gnl, int *i);

//r_init_game_2.c
int	init_config(int *flag, char *gnl, t_params *params);
t_map *load_map(int fd, t_params *params);

//search_function.c
t_position	*put_position_p(t_map *map, char c);
char	find_value(t_map *map, t_position *pos);
void	change_value(t_map *map, t_position *pos, char c);

int	pixel_render(t_params *params);


//x_debuggging

t_rect	*init_rectangle(void);
void	put_rectangle(t_params *params, t_map *map, t_line *line);

t_player	*init_player(void);
void	put_player(t_params *params);

void	put_wall(t_params *params);
void    print_map(t_params *params);
void    print_line(t_line *line);
void print_config(t_params *params);
#endif