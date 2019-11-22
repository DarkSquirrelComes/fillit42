/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akittie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 13:53:36 by akittie           #+#    #+#             */
/*   Updated: 2019/11/22 15:31:06 by akittie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	valid_tetrimin(const char *buff)
{
	int i;
	int num;

	i = 0;
	num = 0;
	while (++i <= 20)
	{
		if (i > 0 && i % 5 == 0)
		{
			if (buff[i - 1] != '\n')
				return (-1);
		}
		else if (buff[i - 1] != '.' && buff[i - 1] != '#')
			return (-1);
		else if (buff[i - 1] == '#')
			num++;
	}
	if (num != 4)
		return (-1);
	return (0);
}

static int	validation_read(int fd)
{
	char	buff[20];
	int		ret;

	while (1)
	{
		if ((ret = read(fd, buff, 20) < 20))
			return (-1);
		if ((valid_tetrimin(buff)))
			return (-1);
		if ((ret = read(fd, buff, 1)) == 0)
			return (0);
		else if (ret < 0 || buff[0] != '\n')
			return (-1);
	}
}

int			check(int ac, char **av)
{
	int fd;

	if (ac != 2)
	{
		write(1, "usage: ./fillit input_file\n", 27);
		return (0);
	}
	if ((fd = open(av[1], O_RDONLY)) < 0 || (validation_read(fd)) < 0)
	{
		write(1, "error\n", 6);
		return (0);
	}
	close(fd);
	return (1);
}
