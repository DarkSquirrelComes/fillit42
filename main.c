/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akittie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 13:48:11 by akittie           #+#    #+#             */
/*   Updated: 2019/11/23 22:51:36 by akittie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "fill_tools.h"

int main(int ac, char **av)
{
	char		**map;
	int n_tetr;
	t_tetr *my_tetr;

	if ((n_tetr = num_valid(ac, av)) <= 0)
		return (0);
	if (!(my_tetr = get_tetr(av[1], n_tetr)))
		return (ft_error());

	write(1, my_tetr[2].tetr[0], 5);
	write(1, "\n", 1);
	write(1, my_tetr[2].tetr[1], 5);
	write(1, "\n", 1);
	write(1, my_tetr[2].tetr[2], 5);
	write(1, "\n", 1);
	write(1, my_tetr[2].tetr[3], 5);
	write(1, "\n", 1);
	write(1, my_tetr[2].tetr[4], 5);
	write(1, "\n", 1);

	int			maps_size=0;
	int			i;

	while (++maps_size)
	{
		map = malloc(sizeof(char*) * (maps_size + 1));
		map[maps_size] = NULL;
		i = -1;
		while (++i < maps_size)
		{
			map[i] = malloc(maps_size + 1);
			map[i][maps_size] = '\0';
		}
		map[maps_size] = NULL;
		for (int i = 0; i < maps_size * maps_size; ++i)
			map[i / maps_size][i % maps_size] = '.';

		fill_with(map, 0, my_tetr, maps_size);
	}	
	return (0);
}

