NAME = push_swap

SRC = index.c main_helper.c main.c operations1.c operations2.c \
		operations3.c operations4.c small_sorting.c

OBJ = $(SRC:.c=.o)

CC = cc

FLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAG) $(OBJ) -o $(NAME)

%.o: %.c Makefile
	@$(CC) $(FLAG) -I. -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re all