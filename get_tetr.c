/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tetr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akittie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 16:45:14 by akittie           #+#    #+#             */
/*   Updated: 2019/11/23 22:58:26 by akittie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		count_y(const char *buff)
{
	int i;
	int n;
	int n_max;

	n_max = 0;
	n = 0;
	i = 0;
	while (++i <= 20)
	{
		if (i % 5 != 0)
		{
			if (buff[i - 1] == '#')
				n++;
		}
		else
		{
			n_max = (n > n_max) ? n : n_max;
			n = 0;
		}
	}
	return (n_max);
}

int		count_x(const char *buff)
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
				n++;
			j += 5;
		}
		n_max = (n > n_max) ? n : n_max;
	}
	return (n_max);
}

int		start_copy_index(const char *buff, t_tetr my_tetr)
{
	int i;
	int j;
	int row;
	int col;

	i = 0;
	while (i < 20 && buff[i] != '#')
		i++;
	row = i;
	col = 0;
	i = -1;
	while (++i < 4)
	{
		j = 0;
		while (i + j < 19)
		{
			col = i + j;
			if (buff[i + j] == '#')
				i = 19;
			j += 5;
		}
	}
	j = (row == col) ? row : (col - (my_tetr.x - 1) * 5);
	return (j);
}

t_tetr	get_one_tetr(char *buff)
{
	int		i;
	int		x;
	int		y;
	int		start;
	t_tetr	my_tetr;

	i = -1;
	while (++i < 25)
		my_tetr.tetr[i / 5][i % 5] = '\0';
	my_tetr.y = count_y(buff);
	my_tetr.x = count_x(buff);
	start = start_copy_index(buff, my_tetr);
	i = start;
	x = 0;
	y = 0;
	while (x < my_tetr.x)
	{
		y = -1;
		while (++y < my_tetr.y)
			my_tetr.tetr[x][y] = buff[i++];
		x++;
		i = start + 5 * x;
	}
	return (my_tetr);
}

t_tetr	*get_tetr(char *file, int n_tetr)
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
		res[i] = get_one_tetr(buff);
		if (i < n_tetr - 1)
			if ((ret = read(fd, buff, 1)) < 0)
				return (0);
	}
	res[n_tetr].x = -1;
	close(fd);
	return (res);
}
