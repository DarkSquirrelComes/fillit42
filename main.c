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
	char		**tetr_map;
	char		**map;
	int n_tetr;
	t_tetr *my_tetr;

	if ((n_tetr = num_valid(ac, av)) <= 0)
		return (0);
	if (!(my_tetr = get_tetr(av[1], n_tetr)))
		return (ft_error());

	int			maps_size = 5;
	int			i;

	map = malloc(sizeof(char*) * (maps_size + 1));
	map[maps_size] = NULL;
	i = -1;
	while (++i < maps_size)
	{
		map[i] = malloc(maps_size + 1);
		map[i][maps_size] = '\0';
	}
	map[maps_size] = NULL;
	for (int i = 0; i < 25; ++i)
		map[i / 5][i % 5] = '.';

	fill_with(map, 0, my_tetr, 5);
	return (0);
}

