#include "fillit.h"
#include "fill_tools.h"

int				main(int ac, char **av)
{
	t_tetr		*my_tetr;
	char		**tetr_map;
	char		**map;

	for (int i = 0; i < 25; ++i)
		my_tetr->tetr[i / 5][i % 5] = '.';
	my_tetr->tetr[0][0] = '#';
	my_tetr->tetr[0][1] = '#';
	my_tetr->tetr[0][2] = '#';
	my_tetr->tetr[0][3] = '#';
	my_tetr->x = 1;
	my_tetr->y = 4;




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
	return 0;

	is_fit(map, my_tetr, 0, 0, 0);
	print_map(map);
}
