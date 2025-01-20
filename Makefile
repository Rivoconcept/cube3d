#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/22 08:39:35 by rhanitra          #+#    #+#              #
#    Updated: 2025/01/20 14:42:18 by rhanitra         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CUBE3D = main.c

DIR_CUBE3D = ./cube3d/
SRC_CUBE3D= $(addprefix $(DIR_CUBE3D),$(CUBE3D))

DIR_MINILIBX = ./minilibx-linux
MINILIBX = $(DIR_MINILIBX)/*.a

DIR_LIBFT = ./libft
LIBFT = $(DIR_LIBFT)/libft.a

OBJ_CUBE3D = $(SRC_CUBE3D:.c=.o)

EXEC = cub3D

CFLAGS = -Wall -Wextra -Werror -g -I $(DIR_MINILIBX) -I $(DIR_LIBFT)
CC = gcc
RM = rm -rf
AR = ar rcs

all : $(EXEC)

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(MINILIBX):
	$(MAKE) -C $(DIR_MINILIBX)


$(LIBFT):
	$(MAKE) -C $(DIR_LIBFT)

$(EXEC) : $(OBJ_CUBE3D) $(LIBFT) $(MINILIBX)
	$(CC)  $(CFLAGS) -o $@ $^ -L$(DIR_GNL) -lgnl \
	-L$(DIR_MINILIBX) -lmlx -lXext -lX11 \

clean :
	$(RM) $(OBJ_CUBE3D)
	$(MAKE) -C $(DIR_LIBFT) clean
	
fclean : clean
	$(RM) $(EXEC)
	$(MAKE) -C $(DIR_LIBFT) fclean

re : fclean all

.PHONY: all clean fclean re
