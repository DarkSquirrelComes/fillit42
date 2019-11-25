/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akittie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 18:08:41 by akittie           #+#    #+#             */
/*   Updated: 2019/11/25 18:09:01 by akittie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "utils.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void		print_map(char **map, int maps_size)
{
	int		i;

	i = -1;
	while (++i < maps_size)
	{
		write(1, map[i], maps_size);
		write(1, "\n", 1);
	}
}
