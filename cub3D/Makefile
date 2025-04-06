# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/22 08:39:35 by rhanitra          #+#    #+#              #
#    Updated: 2025/04/06 13:55:26 by rhanitra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CUB3D = main.c cleanup.c init_params.c put_pixel.c window.c \
		utils_1.c utils_2.c utils_3.c manage_list_1.c  manage_list_2.c \
		handle_game_1.c handle_game_2.c handle_game_3.c search.c \
		init_game_1.c init_game_2.c init_game_3.c render_1.c render_2.c\
		error_1.c error_2.c error_3.c error_4.c \
		init_img.c render_22.c render_222.c\
		player.c cleanup2.c utils_4.c\

DIR_CUB3D = ./src/
SRC_CUB3D= $(addprefix $(DIR_CUB3D),$(CUB3D))

DIR_GNL = ./dependence/gnl
GNL = $(DIR_GNL)/libgnl.a

DIR_MINILIBX = ./dependence/minilibx-linux
MINILIBX = $(DIR_MINILIBX)/libmlx.a $(DIR_MINILIBX)/libmlx_Linux.a

DIR_LIBFT = ./dependence/libft
LIBFT = $(DIR_LIBFT)/libft.a

OBJ_CUB3D = $(SRC_CUB3D:.c=.o)

EXEC = cub3D

CFLAGS = -Wall -Wextra -Werror -g -I $(DIR_GNL) \
	-I $(DIR_MINILIBX) -I $(DIR_LIBFT) -I/usr/include -I/usr/include/X11
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
	$(CC)  $(CFLAGS) -o $@ $^ -L$(DIR_GNL) -lgnl \
		-L$(DIR_MINILIBX) -lmlx -lXext -lX11 -lXext -lm

clean :
	$(RM) $(OBJ_CUB3D)
	$(MAKE) -C $(DIR_GNL) clean
	$(MAKE) -C $(DIR_LIBFT) clean

fclean : clean
	$(RM) $(EXEC)
	$(MAKE) -C $(DIR_GNL) fclean
	$(MAKE) -C $(DIR_LIBFT) fclean
	$(RM) $(DIR_MINILIBX)/libmlx.a $(DIR_MINILIBX)/libmlx_Linux.a

re : fclean all

.PHONY: all clean fclean re
