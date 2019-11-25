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

int			my_sqrt(int x)
{
	int		res;

	res = 0;
	while (res * res < x)
		++res;
	return (res);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(s1);
	s2 = (char *)malloc(len + 1);
	if (s2 == NULL)
		return (NULL);
	while (i < len)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[len] = '\0';
	return (s2);
}

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

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
