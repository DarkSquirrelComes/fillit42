#include "fillit.h"
#include "utils.h"
#include "fill_tools.h"

int				main(int ac, char **av)
{
	t_tetr		my_tetr;
	char		**tetr_map;
	char		**map;

	for (int i = 0; i < 25; ++i)
		my_tetr.tetr[i / 5][i % 5] = '.';

	
	my_tetr.tetr[0][0] = '#';
	my_tetr.tetr[0][1] = '#';
	my_tetr.tetr[0][2] = '#';
	my_tetr.tetr[0][3] = '#';
	my_tetr.x = 1;
	my_tetr.y = 4;

	t_tetr		*t_arr;
	t_arr = malloc(sizeof(t_tetr) * 3);
	t_arr[0] = my_tetr;
	t_arr[1] = my_tetr;
	t_arr[2].x = -1;

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

	fill_with(map, 0, t_arr, 5);
	/*

	is_fit(map, my_tetr, 0, 0, 0);
	is_fit(map, my_tetr, 1, 0, 1);
	is_fit(map, my_tetr, 2, 0, 2);
	print_map(map, 4);*/
}
