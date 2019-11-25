/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akittie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 18:06:02 by akittie           #+#    #+#             */
/*   Updated: 2019/11/25 18:51:52 by akittie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "utils.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

int			is_fit(char **map, t_tetr t, int x, int y)
{
	int		i;
	int		j;

	i = -1;
	while (++i < t.x)
	{
		j = -1;
		while (++j < t.y)
		{
			if (map[x + i][y + j] != '.' && t.tetr[i][j] == '#')
			{
				return (0);
			}
			if (map[x + i][y + j] == '.' && t.tetr[i][j] == '#')
			{
				map[x + i][y + j] = 'A' + t.index;
			}
		}
	}
	return (1);
}

char		**map_cpy(char **map, int maps_size)
{
	int		i;
	char	**res;

	res = malloc(sizeof(char*) * (maps_size + 1));
	res[maps_size] = NULL;
	i = -1;
	while (++i < maps_size)
		res[i] = strdup(map[i]);
	return (res);
}

void		map_free(char ***m, int map_size)
{
	char	**map;
	int		i;

	i = 0;
	map = *m;
	while (i < map_size)
	{
		free(map[i]);
		map[i++] = 0;
	}
	free(m);
}

int			fill_with(char **map, int index, t_tetr *t_arr, int maps_size)
{
	int		i;
	int		j;
	char	**new_map;

	if (t_arr[index].x == -1)
	{
		print_map(map, maps_size);
		exit(0);
	}
	i = -1;
	while (++i <= maps_size - t_arr[index].x)
	{
		j = -1;
		while (++j <= maps_size - t_arr[index].y)
		{
			new_map = map_cpy(map, maps_size);
			if (is_fit(new_map, t_arr[index], i, j))
				if (fill_with(new_map, index + 1, t_arr, maps_size))
					return (1);
			map_free(&new_map, maps_size);
		}
	}
	return (0);
}
