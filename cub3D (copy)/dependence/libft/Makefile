#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhanitra <rhanitra@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/22 08:39:35 by rhanitra          #+#    #+#              #
#    Updated: 2024/09/25 11:13:12 by rhanitra         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

PART1 = ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
ft_memchr.c ft_memcmp.c ft_calloc.c ft_strlen.c ft_strlcpy.c	\
ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strnstr.c	\
ft_strdup.c ft_striteri.c ft_isdigit.c ft_atoi.c ft_isalpha.c \
ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c

PART2 = ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c	\
ft_itoa.c	 ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c 	\
ft_putendl_fd.c ft_putnbr_fd.c

SRC_BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c	\
	ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c

CFLAGS = -Wextra -Wall -Werror -Wall -Wextra -Werror

CC = cc

SRC = $(PART1) $(PART2)

OBJ = $(SRC:.c=.o)

RM = rm -rf

AR = ar rcs

NAME = libft.a

OBJ_BONUS = $(SRC_BONUS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(AR) $(NAME) $^

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $< 

bonus : $(OBJ) $(OBJ_BONUS)
	$(AR) $(NAME) $^

clean :
	$(RM) *.o
	
fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re bonus
