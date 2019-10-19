/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gutorres <gutorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:36:31 by fserlut           #+#    #+#             */
/*   Updated: 2019/10/19 17:54:48 by gutorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		place_fig(t_struct_map *map, t_struct *all_fig_coord, int c_fig)
{
	if (place_one_fig(map, all_fig_coord, c_fig) == 1)
		print_map(*map);
	else
		place_fig(map = free_old_map_cr_new(map, map->sqr_size + 1), \
			all_fig_coord, c_fig);
}

int			place_one_fig(t_struct_map *map, t_struct *all_fig_coord, \
				int all_fig)
{
	int	x_step;
	int	y_step;

	y_step = 0;
	while (y_step + all_fig_coord->height <= map->sqr_size)
	{
		x_step = 0;
		while (x_step + all_fig_coord->width <= map->sqr_size)
		{
			if (!(check_coord(map, all_fig_coord, y_step, x_step) == 1))
				x_step++;
			else if (all_fig_coord->number == all_fig - 1 || \
					place_one_fig(map, ++all_fig_coord, all_fig) == 1)
				return (1);
			else
			{
				del_one_fig(map, --all_fig_coord, x_step, y_step);
				x_step++;
			}
		}
		y_step++;
	}
	return (-1);
}

int			check_coord(t_struct_map *map, t_struct *all_fig, \
				int y_step, int x_step)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (map->map_arr[all_fig->y[i] + y_step][all_fig->x[i] + x_step] != '.')
			return (0);
		i++;
	}
	while (--i >= 0)
		map->map_arr[all_fig->y[i] + y_step][all_fig->x[i] + x_step] = \
			all_fig->letter;
	return (1);
}

void		del_one_fig(t_struct_map *map, t_struct *all_coord, \
				int x_step, int y_step)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		map->map_arr[all_coord->y[i] + y_step][all_coord->x[i] + x_step] = '.';
		i++;
	}
}
