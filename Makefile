# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rcorke <rcorke@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2019/08/12 12:52:08 by rcorke         #+#    #+#                 #
#    Updated: 2019/08/24 14:05:44 by rcorke        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME= push_swap
SOURCES= push_swap.c ps_find_median.c big_algorithm.c sort_3.c \
list_functions.c smart_sort.c smart_sort_2.c check_rotates.c sort_4.c \
small_algo.c get_x_from_stack_a.c get_x_from_stack_a_2.c sort_a_and_b.c \
sort_a_and_b_2.c find_median_sorted.c
OPSRCS= do_ops.c do_ops2.c do_ops3.c lookahead_functions.c command_list.c
CHKSRCS= checker.c check_errors.c ps_gnl.c
PRINTF= libftprintf.a
LIBFT= libft/libft.a
OBJECTS= $(SOURCES:.c=.o)
OPOBJCTS= $(OPSRCS:.c=.o)
CHKOBJCTS= $(CHKSRCS:.c=.o)
FLAGS= -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@make re -C libft/
	@make clean -C libft/
	@echo 'making push_swap'
	@gcc -c $(FLAGS) $(SOURCES) $(OPSRCS)
	@gcc -g $(OBJECTS) $(OPOBJCTS) $(PRINTF) $(LIBFT) -o $(NAME)
	@gcc -c $(FLAGS) $(CHKSRCS) $(OPSRCS)
	@gcc -g $(CHKOBJCTS) $(OPOBJCTS) $(PRINTF) $(LIBFT) -o checker

clean:
	@make clean -C libft/
	@rm -rf *~ $(OBJECTS) $(OPOBJCTS) $(CHKOBJCTS)

fclean: clean
	@make fclean -C libft/
	@rm -rf $(NAME) checker

re: fclean all
