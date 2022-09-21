NAME = push_swap

SRC = $(wildcard *.c)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./ft_printf
	make -C ./libft
	$(CC) $(CFLAGS) $(SRC) ./libft/libft.a ./ft_printf/libftprintf.a -o $(NAME)


clean:
	rm -rf $(OBJ)
	rm -rf main.o
	make -C ./ft_printf clean
	make -C ./libft clean

fclean: clean
	rm -rf $(OBJ) $(NAME)
	make -C ./ft_printf fclean
	make -C ./libft fclean

re: fclean all

.PHONY: all re clean fclean
