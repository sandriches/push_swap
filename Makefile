# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rcorke <rcorke@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2019/05/01 19:10:09 by rcorke         #+#    #+#                 #
#    Updated: 2019/06/04 14:18:36 by rcorke        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME= push_swap
SOURCES= tester_push_swap.c do_ops.c libft/libft.a libftprintf.a

all:
	gcc -g -Wall -Wextra $(SOURCES) -o $(NAME)
	./push_swap 283	-963	213	-353	172	659	206	-175	-249	-1	-624 -50 9999999	59200 -441	-904 4242 -69	920 -101010 -4902 -55037 60	969	-719	-376	455	653	480	894	-142