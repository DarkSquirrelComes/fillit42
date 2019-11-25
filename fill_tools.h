/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_tools.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akittie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 18:11:13 by akittie           #+#    #+#             */
/*   Updated: 2019/11/25 18:52:15 by akittie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILL_TOOLS_H
# define FILL_TOOLS_H

# include "fillit.h"
# include "utils.h"
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int			**is_fit(char **map, t_tetr t, int x, int y);
char		**map_cpy(char **map, int maps_size);
void		map_free(char ***map, int i);
int			fill_with(char **map, int index, t_tetr *t_arr, int maps_size);
#endif
