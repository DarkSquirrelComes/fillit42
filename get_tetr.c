/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tetr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akittie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 16:45:14 by akittie           #+#    #+#             */
/*   Updated: 2019/11/25 18:36:05 by akittie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		count_y(const char *buff)
{
	int i;
	int n;
	int n_max;

	n_max = 0;
	n = 0;
	i = 0;
	while (++i <= 20)
	{
		if (i % 5 != 0 && buff[i - 1] == '#')
		{
			n++;
			if ((i > 4 && buff[i] != '#' && buff[i - 5] == '#') ||
				(i < 14 && buff[i] != '#' && buff[i + 5] == '#'))
				n++;
		}
		else if (i % 5 == 0)
		{
			n_max = (n > n_max) ? n : n_max;
			n = 0;
		}
	}
	return (n_max);
}

static int		count_x(const char *buff)
{
	int i;
	int j;
	int n;
	int n_max;

	n_max = 0;
	i = -1;
	while (++i < 4)
	{
		n = 0;
		j = 0;
		while (i + j < 19)
		{
			if (buff[i + j] == '#')
			{
				n++;
				if ((i + j) < 14 && buff[i + j + 5] != '#' &&
					(buff[i + j + 4] == '#' || buff[i + j + 6] == '#'))
					n++;
			}
			j += 5;
		}
		n_max = (n > n_max) ? n : n_max;
	}
	return (n_max);
}

static void		prettyfy(char t_map[5][5])
{
	int	i;

	while (t_map[0][0] == '.' && t_map[0][1] == '.'
			&& t_map[0][2] == '.' && t_map[0][3] == '.')
	{
		i = 4;
		while (i < 16)
		{
			t_map[i / 4 - 1][i % 4] = t_map[i / 4][i % 4];
			t_map[i / 4][i % 4] = '.';
			++i;
		}
	}
	while (t_map[0][0] == '.' && t_map[1][0] == '.'
			&& t_map[2][0] == '.' && t_map[3][0] == '.')
	{
		i = 4;
		while (i < 16)
		{
			t_map[i % 4][i / 4 - 1] = t_map[i % 4][i / 4];
			t_map[i % 4][i / 4] = '.';
			++i;
		}
	}
}

static t_tetr	get_one_tetr(char *buff, int index)
{
	int		x;
	int		y;
	t_tetr	my_tetr;

	my_tetr.y = count_y(buff);
	my_tetr.x = count_x(buff);
	my_tetr.index = index;
	x = -1;
	while (++x < 5)
	{
		y = -1;
		while (++y < 5)
			my_tetr.tetr[x][y] = buff[5 * x + y];
	}
	prettyfy(my_tetr.tetr);
	return (my_tetr);
}

t_tetr			*get_tetr(char *file, int n_tetr)
{
	int		i;
	int		fd;
	char	buff[20];
	ssize_t ret;
	t_tetr	*res;

	if (!(res = (t_tetr *)malloc(sizeof(t_tetr) * (n_tetr + 1))) ||
			((fd = open(file, O_RDONLY)) < 0))
		return (0);
	i = -1;
	while (++i < n_tetr)
	{
		if ((ret = read(fd, buff, 20) < 0))
			return (0);
		res[i] = get_one_tetr(buff, i);
		if (i < n_tetr - 1)
			if ((ret = read(fd, buff, 1)) < 0)
				return (0);
	}
	res[n_tetr].x = -1;
	close(fd);
	return (res);
}
