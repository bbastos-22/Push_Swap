# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbastos- <bbastos-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/24 14:30:35 by bbastos-          #+#    #+#              #
#    Updated: 2026/03/02 16:14:34 by bbastos-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Werror -Wextra -I./includes -I./libs/Libft -I./libs/Printf
RM = rm -f

SRCS =	srcs/main.c
		utils/error.c
		utils/free.c
		utils/stack_utils.c

LIBFT = libs/Libft/libft.a
PRINTF = libs/Printf/libftprintf.a

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME)

$(LIBFT):
	make -C libs/Libft

$(PRINTF):
	make -C libs/Printf

clean:
    $(RM) $(OBJS)
    make clean -C libs/Libft
    make clean -C libs/Printf

fclean: clean
    $(RM) $(NAME)
    make fclean -C libs/Libft
    make fclean -C libs/Printf

re: fclean all

.PHONY: all clean fclean re