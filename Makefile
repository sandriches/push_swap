# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rcorke <rcorke@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2019/05/01 19:10:09 by rcorke         #+#    #+#                 #
#    Updated: 2019/05/31 18:39:16 by rcorke        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME= push_swap
SOURCES= tester_push_swap.c do_ops.c libft/libft.a libftprintf.a

all:
	gcc -g -Wall -Wextra $(SOURCES) -o $(NAME)
	./push_swap 7 2 9 3 1 5

