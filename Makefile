NAME = push_swap

SRC = main.c error.c utils.c moves1.c moves2.c sort.c \
	stack_init.c stack_init2.c stack_utils1.c stack_utils2.c\
	ft_split.c

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Werror -Wextra -g

DEL = rm -rf

AR = ar -rcs

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

all: $(NAME)

clean:
	$(DEL) $(OBJ)

fclean: clean
	$(DEL) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus