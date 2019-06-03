# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rcorke <rcorke@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2019/05/01 19:10:09 by rcorke         #+#    #+#                 #
#    Updated: 2019/06/03 16:16:45 by rcorke        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME= push_swap
SOURCES= tester_push_swap.c do_ops.c libft/libft.a libftprintf.a

all:
	gcc -g -Wall -Wextra $(SOURCES) -o $(NAME)
	./push_swap 439	861	212	948	265	259	812	790 450 220 111 420
