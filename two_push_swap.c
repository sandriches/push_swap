/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   two_push_swap.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/05 10:20:29 by rcorke         #+#    #+#                */
/*   Updated: 2019/07/05 10:54:25 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void get_next_to_push(p_a *ps)
{
    int *indexes;
    int index_array[2];

    index_array[0] = 2147483647;
    index_array[1] = 2147483647;
    indexes = index_array;
    
}

void        push_two_random(p_a *ps)
{
    int x;

    x = 0;
    push_a(ps);
    push_a(ps);
}