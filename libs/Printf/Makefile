# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbastos- <bbastos-@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/06 09:04:24 by bbastos-          #+#    #+#              #
#    Updated: 2025/11/17 12:16:19 by bbastos-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

INCLUDE = printf.h

CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

SRCS = ft_printf.c ft_putchar_pf.c ft_putstr_pf.c\
	   ft_putnbr_pf.c ft_printdec.c ft_printhex.c\
	   ft_printptr.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)
re: fclean all

.PHONY: all re clean fclean
