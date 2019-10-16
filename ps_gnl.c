/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_gnl.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/07 14:33:02 by rcorke         #+#    #+#                */
/*   Updated: 2019/07/21 14:47:29 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char		*fill_line(char **leftover, char **line)
{
	int		len;
	char	*tmp;

	if (ft_memchr(*leftover, '\n', ft_strlen(*leftover)) != NULL)
	{
		len = ft_strcharloc(*leftover);
		tmp = *leftover;
		*line = ft_strndup(*leftover, len);
		*leftover = ft_strdup(tmp + len + 1);
		free(tmp);
	}
	else
	{
		*line = ft_strdup(*leftover);
		ft_memdel((void **)leftover);
		free(*leftover);
	}
	return (*line);
}

static int		last_fill_line(char **leftover, char **line)
{
	fill_line(leftover, line);
	return (1);
}

static int		read_line(int fd, char **leftover, char **line)
{
	char	buf[101];
	int		ret;
	char	*tmp;

	ret = 1;
	while (ret > 0)
	{
		ret = read(fd, buf, 100);
		if (ret == -1)
			return (-1);
		if (ret == 0)
			break ;
		buf[ret] = '\0';
		tmp = *leftover;
		*leftover = ft_strjoin(*leftover, buf);
		free(tmp);
		if (ft_memchr(buf, '\n', ret) != NULL || ret < 100)
		{
			*line = fill_line(leftover, line);
			return (1);
		}
	}
	if (*leftover && ft_strlen(*leftover))
		return (last_fill_line(leftover, line));
	return (0);
}

int				ps_get_next_line(const int fd, char **line)
{
	static char		*leftover;
	int				check;

	if (!line)
		return (-1);
	if (!leftover)
		leftover = ft_strnew(0);
	check = read_line(fd, &leftover, line);
	if (check == 0)
		return (0);
	else if (check == 1)
		return (1);
	return (-1);
}
