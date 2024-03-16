# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mimoreir <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/05 09:19:32 by mimoreir          #+#    #+#              #
#    Updated: 2022/12/05 09:19:34 by mimoreir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
CC		= clang
CFLAGS	= -Wall -Werror -Wextra
RM		= rm -f
AR		= ar rcs

SRCS	= \
	push_swap.c init_list.c verify_list.c ops_a.c ops_b.c \
	ops_both.c sorting_small.c sorting_large.c sorting_utils.c \
	sorting_utils2.c sorting_above_100.c sort_100_utils.c

OBJS = $(SRCS:.c=.o)

all:	$(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	$(CC) $(SRCS) $(NAME) -o push_swap

clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME) push_swap

re: fclean all
