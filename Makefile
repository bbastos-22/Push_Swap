# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbastos- <bbastos-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/24 14:30:35 by bbastos-          #+#    #+#              #
#    Updated: 2026/03/05 00:03:06 by bbastos-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Werror -Wextra -I./includes -I./libs/Libft
RM = rm -f

SRCS =	srcs/main.c
		utils/error.c
		utils/free.c
		utils/stack_utils.c

LIBFT = libs/Libft/libft.a

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C libs/Libft

clean:
    $(RM) $(OBJS)
    make clean -C libs/Libft

fclean: clean
    $(RM) $(NAME)
    make fclean -C libs/Libft

re: fclean all

.PHONY: all clean fclean re