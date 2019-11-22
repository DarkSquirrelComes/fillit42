#include "fillit.h"
#include "utils.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int		**is_fit(char **map, t_tetrimino t, int x, int y, int index)
{
	int		i;
	int		j;

	i = -1;
	while (++i < t.x)
	{
		j = -1;
		while (++j <= t.y)
			if (map[x + i][y + j] != '.' && t.tetr[i][j] == '#')
				return (NULL);
			if (map[x + i][y + j] == '.' && t.tetr[i][j] == '#')
				map[x + i][y + j] = 'A' + index;
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

void		map_free(char **map)
{
	while (*map)
	{
		free(*map);
		*map += 1;
	}
}

int			fill_with(char **map, int index, t_tetrimino *t_arr, int maps_size)
{
	int		i;
	int		j;
	char	**new_map;

	if (t_arr[index])
	{
		print_map(map, maps_size);
		return (1);
	}
	i = -1;
	while (++i <= maps_size - t_arr[index].x)
	{
		j = -1;
		while (++j <= maps_size - t_arr[index].y)
		{
			new_map = map_cpy(map, maps_size);
			if (is_fit(new_map, t_arr[index]), i, j, index)
				if (fill_with(new_map, index + 1, t_arr, maps_size))
					return (1);
			map_free(new_map);
		}
	}
}
