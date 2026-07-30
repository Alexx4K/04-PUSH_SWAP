NAME = push_swap.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

HEADERS = push_swap.h

SRC = parsing/flags_comparing.c\
	parsing/flags.c\
	parsing/parser.c\
	parsing/utils.c\
	sort/ft_adaptive.c\
	sort/ft_chunksort.c\
	sort/ft_radix.c\
	sort/selection_sort.c\
	sort/small_sort.c\
	sort/sorting_utils.c\
	stack/ft_push.c\
	stack/ft_rotate.c\
	stack/ft_swap.c\
	tests/test_indexed_sort.c\
	tests/testing_main.c\
	tests/testSortSel.c\
	ft_bench.c\
	linked_lists.c\
	list_utils.c\
	main.c\
	push_swap.c\

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
