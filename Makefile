# ************************************************************************** #
#                                                                            #
#                                                        :::      ::::::::   #
#   Makefile                                           :+:      :+:    :+:  #
#                                                    +:+ +:+         +:+     #
#   By: crubio-p <crubio-p@student.42madrid.com>   +#+  +:+       +#+       #
#                                                +#+#+#+#+#+   +#+          #
#   Created: 2026/07/30 18:06:25 by crubio-p          #+#    #+#            #
#   Updated: 2026/07/30 18:06:25 by crubio-p         ###   ########.fr      #
#                                                                            #
# ************************************************************************** #

NAME		=	push_swap

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f

LIBFT_DIR	=	libft
LIBFT		=	$(LIBFT_DIR)/libft.a

SRCS		=	main.c \
				push_swap.c \
				linked_lists.c \
				list_utils.c \
				ft_bench.c \
				parsing/parser.c \
				parsing/tokenizer.c \
				parsing/utils.c \
				parsing/flags.c \
				parsing/flags_comparing.c \
				sort/selection_sort.c \
				sort/small_sort.c \
				sort/ft_chunksort.c \
				sort/ft_radix.c \
				sort/ft_adaptive.c \
				sort/sorting_utils.c \
				stack/ft_push.c \
				stack/ft_rotate.c \
				stack/ft_swap.c

OBJS		=	$(SRCS:.c=.o)

%.o:		%.c push_swap.h
			$(CC) $(CFLAGS) -I. -c $< -o $@

$(NAME):	$(LIBFT) $(OBJS)
			$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
			$(MAKE) -C $(LIBFT_DIR)

all:		$(NAME)

bonus:		all

clean:
			$(RM) $(OBJS)
			$(MAKE) -C $(LIBFT_DIR) clean

fclean:		clean
			$(RM) $(NAME)
			$(MAKE) -C $(LIBFT_DIR) fclean

re:			fclean all

.PHONY:		all bonus clean fclean re
