/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_sqrt.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/26 15:33:28 by rcorke         #+#    #+#                */
/*   Updated: 2019/06/26 15:38:42 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     ft_sqrt(int n)
{
    int x;

    x = 1;
    while (n > 0)
    {
        n /= 2;
        x++;
    }
    return (x);
}

int     main(void)
{
    int x = 64;
    ft_printf("result: %d\n", ft_sqrt(x));
}