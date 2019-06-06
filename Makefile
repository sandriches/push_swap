# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rcorke <rcorke@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2019/05/01 19:10:09 by rcorke         #+#    #+#                 #
#    Updated: 2019/06/06 19:54:09 by rcorke        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME= push_swap
SOURCES= tester_push_swap.c do_ops.c libft/libft.a libftprintf.a ps_quicksort.c\
		ps_insertion_sort.c

all:
	gcc -g -Wall -Wextra $(SOURCES) -o $(NAME)
	./push_swap 5 2 1 4 3 400 42 222 100 2002 4242 5235 50 49 29 110 4141 199 2522 420