FLAGS = -Wall -Wextra -Werror
CC = cc
RM = rm -rf

EXAMSHELL = main.c ft_parser.c utils.c ft_strcmp.c ft_strdup.c ft_strlen.c init_list_cmd.c exec.c \
			format_quotes.c

DIR_EXAMSHELL = ./

SRC_EXAMSHELL = $(addprefix $(DIR_EXAMSHELL), $(EXAMSHELL))

OBJ_EXAMSHELL = $(SRC_EXAMSHELL:.c=.o)

EXEC = microshell

all = $(EXEC)

%.o : %.c
	$(CC) $(FLAGS) -o $@ -c $<

$(EXEC) : $(OBJ_EXAMSHELL)
	$(CC) $(FLAGS) -o $@ $^ -lreadline

clean :	
	$(RM) $(OBJ_EXAMSHELL)

fclean : clean
	$(RM) $(EXEC)

re : fclean all

.PHONY : all clean fclean re
