# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbastos- <bbastos-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/24 14:30:35 by bbastos-          #+#    #+#              #
#    Updated: 2026/03/31 18:18:32 by bbastos-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

INCLUDE = push_swap.h

CC = cc
CFLAGS = -Wall -Werror -Wextra -I./includes -I./libs/Libft
RM = rm -f

SRCS =	srcs/main.c utils/free.c utils/parse.c\
		utils/stack_utils.c ops/push.c ops/swap.c\
		ops/reverse_rotate.c ops/rotate.c srcs/sort.c\
		utils/stack_helpers.c

LIBFT = libs/Libft/libft.a

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C libs/Libft

clean:
	$(RM) $(OBJS)
	$(MAKE) clean -C libs/Libft

fclean:	clean
	$(RM) $(NAME)
	$(MAKE) fclean -C libs/Libft

re: fclean all

.PHONY: all clean fclean re