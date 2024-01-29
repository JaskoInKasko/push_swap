CC = cc
CFLAGS = -Wall -Wextra -Werror -g
HEAD = push_swap.h
SRC = Sourcecode/push_swap.c Sourcecode/errors.c Sourcecode/free_all.c Sourcecode/utils.c\
Sourcecode/utils2.c Sourcecode/sort.c Sourcecode/operations.c Sourcecode/radix.c\

OBJ = $(SRC:.c=.o)
NAME = push_swap
LIBFT = ./included_functions/libft/libft.a
FT_PRINTF = ./included_functions/ft_printf/libftprintf.a

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C included_functions/libft --no-print-directory
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(FT_PRINTF) -o $(NAME)

.PHONY: all clean fclean re included_functions

clean:
	$(MAKE) -C included_functions/libft clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -C included_functions/libft fclean
	rm -f $(NAME)

re: fclean all
