# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/22 08:39:35 by rhanitra          #+#    #+#              #
#    Updated: 2025/01/22 18:35:29 by rhanitra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CUB3D = main.c init_game.c manage_list_1.c manage_list_2.c movement_2.c \
		manage_list_3.c check_data_error.c check_wall_error.c cleanup_1.c \
		cleanup_2.c check_flood_fill.c check_error.c search_function.c \
		img_load_1.c img_load_2.c img_load_3.c img_load_4.c img_put_1.c \
		img_put_2.c img_put_3.c img_put_4.c img_put_5.c put_images.c \
		movement_1.c check_error_wall.c

DIR_CUB3D = ./cube3d/
SRC_CUB3D= $(addprefix $(DIR_CUB3D),$(CUB3D))

DIR_GNL = ./dependence/gnl
GNL = $(DIR_GNL)/*.a

DIR_MINILIBX = ./dependence/minilibx-linux
MINILIBX = $(DIR_MINILIBX)/*.a

DIR_LIBFT = ./dependence/libft
LIBFT = $(DIR_LIBFT)/libft.a

OBJ_CUB3D = $(SRC_CUB3D:.c=.o)

EXEC = cub3D

CFLAGS = -Wall -Wextra -Werror -g -I $(DIR_GNL) -I $(DIR_MINILIBX) -I $(DIR_LIBFT) -I/usr/include -I/usr/include/X11
CC = gcc
RM = rm -rf
AR = ar rcs

all : $(EXEC)

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(GNL):
	$(MAKE) -C $(DIR_GNL)

$(MINILIBX):
	$(MAKE) -C $(DIR_MINILIBX)

$(LIBFT):
	$(MAKE) -C $(DIR_LIBFT)

$(EXEC) : $(OBJ_CUB3D) $(GNL) $(LIBFT) $(MINILIBX)
	$(CC)  $(CFLAGS) -o $@ $^ -L$(DIR_GNL) -lgnl -L$(DIR_MINILIBX) -lmlx -lXext -lX11 -lXext

clean :
	$(RM) $(OBJ_CUB3D)
	$(MAKE) -C $(DIR_GNL) clean
	$(MAKE) -C $(DIR_LIBFT) clean
	
fclean : clean
	$(RM) $(EXEC)
	$(MAKE) -C $(DIR_GNL) fclean
	$(MAKE) -C $(DIR_LIBFT) fclean

re : fclean all

.PHONY: all clean fclean re
