LLNAME = linked_lists.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

HEADERS = linked_lists.h

SRC = ft_swap.c \
	ft_push.c \
	ft_rotate.c \
	linked_lists.c

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
