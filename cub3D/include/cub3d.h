/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 22:13:12 by ttelolah          #+#    #+#             */
/*   Updated: 2025/04/06 12:31:10 by rhanitra         ###   ########.fr       */
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
# include <math.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# define RED_PIXEL 0xFF0000
# define SCREEN_WIDTH 1024
# define SCREEN_HEIGHT 720
# define SLICE_SIZE 64
# define PI 3.14159265359
# define FOV 0.785398163
# define SPEED 5.0
# define STEP_CAST 1.0
# define ESC 53
# define X_EVENT_KEY_PRESS 0
# define X_EVENT_KEY_RELEASE 1
# define X_EVENT_EXIT 17
# define W 119
# define A 97
# define S 115
# define D 100

typedef struct s_raycast
{
	float	distance;
	float	rx;
	float	ry;
	float	dir_x;
	float	dir_y;
	char	wall_path;
}	t_raycast;

typedef struct s_wall_draw
{
	int		wall_height;
	int		start;
	int		end;
	int		y;
	float	tex_x;
	float	val;
	float	tex_y;
	int		color;
}	t_wall_draw;

typedef struct s_point
{
	int					x;
	int					y;
}						t_point;

typedef struct s_moov
{
	char				real;
	char				left;
	char				right;
	char				up;
	char				down;
	char				ul;
	char				ur;
	char				dr;
	char				dl;
}						t_moov;

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

typedef struct s_f
{
	int					r;
	int					g;
	int					b;
}						t_f;

typedef struct s_c
{
	int					r;
	int					g;
	int					b;
}						t_c;

typedef struct s_player
{
	char				init;
	char				dir;
	int					x;
	int					y;
	int					width;
	int					height;
	int					color;
}						t_player;

typedef struct s_rect
{
	int					x;
	int					y;
	int					width;
	int					height;
	int					color;
}						t_rect;

typedef struct s_path
{
	char				*no;
	char				*so;
	char				*we;
	char				*ea;
	char				*f;
	char				*c;
}						t_path;

typedef struct s_img
{
	void				*img;
	char				*data;
	int					bpp;
	int					line_len;
	int					endian;
	int					width;
	int					height;
	char				wall_path;
	int					wx;
	int					wy;
	float				distance;
}						t_img;

typedef struct s_params
{
	void				*mlx_connexion;
	void				*win_open;
	char				**map;
	t_img				*screen;
	t_img				*texture;
	t_img				*no;
	t_img				*so;
	t_img				*ea;
	t_img				*we;
	t_position			*pos;
	t_f					*f_color;
	t_c					*c_color;
	t_rect				*rect;
	t_player			*player;
	t_path				*path;
	int					map_width;
	int					map_height;
	float				delta;
	int					win_width;
	int					win_height;
	struct s_params		*next;
}						t_params;

int						check_x_side(t_params *params);
int						check_y_side(t_params *params);
int						check_error_wall(char c, t_params *params);
int						check_map(t_params *params);
int						out_of_play(t_params *params);
int						check_error(int fd, t_params *params);
int						count_data_game(t_params *params, char c);
void					check_first_line_is_valid(int fd, char *gnl, char *str, t_params *params);
int						check_intrus_data(t_params *params);
int						check_extension(char *str);
void					clear_img(t_params *params);
void					cleanup(t_params *params);
t_rect					*init_rectangle(void);
int						draw_rectangle(t_params *params);
void					put_wall(t_params *params);
void					rotate_and_draw(int x, int y, float \
angle, t_params *params);
int						draw_player(t_params *params, int x, int y);
void					put_player(t_params *params);
int						handle_mouse_click(t_params *params);
void					escape_window(int keycode, t_params *params);
int						encode_color(uint8_t r, uint8_t g, uint8_t b);
void					my_mlx_pixel_put(int x, int y, int color,
							t_params *params);
int						direction_calc(float *x, float *y, int keycode,
							t_params *params);
int						handle_keypress(int keycode, t_params *params);
char					*copy_config(char *gnl, int *i);
int						in_base(char *gnl);
int						put_data_config(t_params *params, char *gnl, int *i);
int						init_config(int *flag, char *gnl, char *str,
							t_params *params);
char					**load_map(int fd, t_params *params);
void					init_player(t_params *params);
t_position				*create_list_position(void);
t_f						*init_ground_color(void);
t_c						*init_ceiling_color(void);
t_player				*init_list_player(void);
t_img					*init_list_img(void);
void					init_map_size(t_params *params);
void					free_list_position(t_position *head);
t_params				*create_list_param(void);
void					get_distance(t_params *params, t_img **wall,
							float angle);
void					ray_trace(t_params *params, float angle,
							float distance);
void					trace_fov(t_params *params);
int						get_wall_height(float distance);
void					render_scene(t_params *params);
int						draw_loop(t_params *params);
char					find_value(t_params *params);
char					putval(t_params *params, int x, int y);
char					put_map_value(t_params *params, int x, int y);
int						ft_is_space(char c);
int						perror_msg(char *error, char *var);
void					ft_exit_faillure(t_params *params, int fd, char *error,
							char *var);
void					free_array(char **arr);
int						find_char(char *str, char c);
void					parse_color(t_params *params, char *color, int i,
							int value);
int						check_error_color(char *color, t_params *params);
int						invalid_color_config(char *color);
int						check_error_config(t_params *params);
int						is_only_space(char *str);
int					is_all_config_set(t_params *params, int *flag,
							char *gnl, char *str);
int						get_pos_x(int x, t_params *params);
int						get_pos_y(int y, t_params *params);
void					modulo_angle(float *angle);
t_img					*init_player_direction(t_params *params);
void					rotate_player(int keycode, t_params *params);
void					load_all_textures(t_params *params);
t_img					*init_img_screen(t_params *params);
int						get_texture_pixel(t_img *texture, int x, int y);
int						is_map_line(char *str);
void					update_player_dir(t_params *params);
void					handle_free(char *str);
char					get_type_texture(t_params *params, int x, int y);
void					draw_wall_slice(t_params *params, t_img *wall, int x);
void					get_distance(t_params *params, t_img **wall, \
						float angle);
int						is_format_color(char *color);
#endif