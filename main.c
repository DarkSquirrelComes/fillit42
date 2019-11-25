/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akittie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 13:48:11 by akittie           #+#    #+#             */
/*   Updated: 2019/11/25 19:16:32 by akittie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "fill_tools.h"

void	solving(t_tetr *my_tetr)
{
	char		**map;
	int			maps_size;
	int			i;

	maps_size = 0;
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
		i = 0;
		while (i < maps_size * maps_size)
		{
			map[i / maps_size][i % maps_size] = '.';
			++i;
		}
		fill_with(map, 0, my_tetr, maps_size);
		map_free(&map, maps_size);
	}
}

int		main(int ac, char **av)
{
	int			n_tetr;
	t_tetr		*my_tetr;

	if ((n_tetr = num_valid(ac, av)) <= 0 || n_tetr > 26)
		return (0);
	if (!(my_tetr = get_tetr(av[1], n_tetr)))
		return (ft_error());
	solving(my_tetr);
	return (0);
}
