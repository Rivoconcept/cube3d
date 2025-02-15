# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/22 08:39:35 by rhanitra          #+#    #+#              #
#    Updated: 2024/08/15 10:38:16 by rhanitra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#*****************VARIABLES****************************************

#SOLONG
GNL = get_next_line.c get_next_line_utils.c

DIR_GNL = ./
SRC_GNL = $(addprefix $(DIR_GNL),$(GNL))

OBJ_GNL = $(SRC_GNL:.c=.o)

#****************TARGET**********************************************
NAME = libgnl.a

#****************COMMAND**********************************************
CFLAGS = -Wall -Wextra -Werror
CC = gcc
RM = rm -rf
AR = ar rcs

#*********************CODE********************************************

all : $(NAME)

$(NAME) : $(OBJ_GNL)
	$(AR) $(NAME) $^

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean :
	$(RM) $(OBJ_GNL)
	
fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re
