#ifndef FILL_TOOLS_H
#define FILL_TOOLS_H

//# include "libft.h"
#include "fillit.h"
#include "utils.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int			**is_fit(char **map, t_tetrimino t, int x, int y, int index);
char		**map_cpy(char **map, int maps_size);
void		map_free(char **map);
int			fill_with(char **map, int index, t_tetrimino *t_arr, int maps_size);
#endif
