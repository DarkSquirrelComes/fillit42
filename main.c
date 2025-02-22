/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akittie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 13:48:11 by akittie           #+#    #+#             */
/*   Updated: 2019/11/25 20:10:02 by akittie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "fill_tools.h"
#include "utils.h"

void	solving(t_tetr *my_tetr, int n_tetr)
{
	char		**map;
	int			maps_size;
	int			i;

	maps_size = my_sqrt(4 * n_tetr) - 1;
	while (++maps_size)
	{
		if (!(map = malloc(sizeof(char*) * (maps_size + 1))))
			ft_error();
		map[maps_size] = NULL;
		i = -1;
		while (++i < maps_size)
		{
			if (!(map[i] = malloc(maps_size + 1)))
				ft_error();
			map[i][maps_size] = '\0';
		}
		i = -1;
		while (++i < maps_size * maps_size)
			map[i / maps_size][i % maps_size] = '.';
		fill_with(map, 0, my_tetr, maps_size);
		map_free(&map, maps_size);
	}
}

int		main(int ac, char **av)
{
	int			n_tetr;
	t_tetr		*my_tetr;

	if ((n_tetr = num_valid(ac, av)) <= 0)
		return (0);
	if (!(my_tetr = get_tetr(av[1], n_tetr)))
		ft_error();
	solving(my_tetr, n_tetr);
	return (0);
}
