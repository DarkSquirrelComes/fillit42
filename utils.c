#include "fillit.h"
#include "utils.h"
#include "tetrimino.h"
#include <stdlib.h>

void		print_map(char **map, int maps_size)
{
	int		i;

	i = -1;
	while (++i < maps_size)
	{
		write(1, map[i], maps_size);
		write(1, "\n", 1);
	}
	exit();
}