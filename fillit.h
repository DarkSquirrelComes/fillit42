/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akittie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 13:39:16 by akittie           #+#    #+#             */
/*   Updated: 2019/11/23 19:20:12 by akittie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>

typedef struct	s_tetr
{
	int			x;
	int			y;
	char		tetr[5][5];
}				t_tetr;

int				num_valid(int ac, char **av);
int 			ft_error(void);
t_tetr			*get_tetr(char *file, int n_tetr);

#endif
