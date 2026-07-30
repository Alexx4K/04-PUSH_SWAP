NAME = push_swap.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

HEADERS = push_swap.h

SRC = ft_swap.c \
	ft_push.c \
	ft_rotate.c \
	linked_lists.c\
	main.c\
	push_swap.c\
	ft_bench.c\
	list_utils.c\
	
	

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

all: $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
