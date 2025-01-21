#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/22 08:39:35 by rhanitra          #+#    #+#              #
#    Updated: 2025/01/21 07:08:39 by rhanitra         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CUB3D = main.c 

DIR_SOLONG = ./solong/
SRC_SOLONG= $(addprefix $(DIR_SOLONG),$(SOLONG))

DIR_GNL = ./gnl
GNL = $(DIR_GNL)/*.a

DIR_MINILIBX = ./minilibx-linux
MINILIBX = $(DIR_MINILIBX)/*.a

DIR_FT_PRINTF = ./ft_printf
FT_PRINTF = $(DIR_FT_PRINTF)/libftprintf.a

DIR_LIBFT = ./libft
LIBFT = $(DIR_LIBFT)/libft.a

OBJ_SOLONG = $(SRC_SOLONG:.c=.o)

EXEC = so_long

CFLAGS = -Wall -Wextra -Werror -g -I $(DIR_GNL) -I $(DIR_MINILIBX) \
	-I $(DIR_FT_PRINTF) -I $(DIR_LIBFT)
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

$(FT_PRINTF):
	$(MAKE) -C $(DIR_FT_PRINTF)

$(LIBFT):
	$(MAKE) -C $(DIR_LIBFT)

$(EXEC) : $(OBJ_SOLONG) $(GNL) $(FT_PRINTF) $(LIBFT) $(MINILIBX)
	$(CC)  $(CFLAGS) -o $@ $^ -L$(DIR_GNL) -lgnl \
	-L$(DIR_MINILIBX) -lmlx -lXext -lX11 \
	-L$(DIR_FT_PRINTF) -lftprintf -L$(DIR_LIBFT) -lft

clean :
	$(RM) $(OBJ_SOLONG)
	$(MAKE) -C $(DIR_GNL) clean
	$(MAKE) -C $(DIR_FT_PRINTF) clean
	$(MAKE) -C $(DIR_LIBFT) clean
	
fclean : clean
	$(RM) $(EXEC)
	$(MAKE) -C $(DIR_GNL) fclean
	$(MAKE) -C $(DIR_FT_PRINTF) fclean
	$(MAKE) -C $(DIR_LIBFT) fclean

re : fclean all

.PHONY: all clean fclean re
