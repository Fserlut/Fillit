/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fserlut <fserlut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:36:31 by fserlut           #+#    #+#             */
/*   Updated: 2019/10/16 20:45:39 by fserlut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

// Добавить алгоритм, который удаляет fig - 1 и вставляет туда fig

void	place_fig(t_map *map, t_struct *all_fig_coord, int c_fig)
{
	int n_fig;

	n_fig = 0;
	while (n_fig < c_fig)
	{
		if (place_one_fig (map, all_fig_coord, &n_fig) == 1)
			n_fig++;
		else
		{
			map = free_old_map_cr_new(map, map->sqr_size + 1);
			n_fig = 0;
			while (n_fig < c_fig)
				move_fig_in_struct(&all_fig_coord[n_fig++]);
			n_fig = 0;
		}
	}
	print_map(*map);
}

int			place_one_fig(t_map *map, t_struct *all_fig_coord, int *n_fig)
{
	int i;

	i = 0;
	if (check_coord(map, &all_fig_coord[*n_fig]) == 1)
	{
		while (i < 4)
		{
			map->map_arr[all_fig_coord[*n_fig].y[i]][all_fig_coord[*n_fig].x[i]] =
			all_fig_coord[*n_fig].letter;
			i++;
		}
		return (1);
	}
	if (move_fig_x(&all_fig_coord[*n_fig], map) == 1)
		return (place_one_fig(map, all_fig_coord, n_fig));
	else if (move_fig_y(&all_fig_coord[*n_fig], map) == 1)
		return(place_one_fig(map, all_fig_coord, n_fig));
	else if (del_one_fig(map, &all_fig_coord[*n_fig - 1]) == 1)
		return (place_one_fig(map, all_fig_coord, n_fig));
	else
		return (-1);
}

int			move_fig_x(t_struct *all_fig_coord, t_map *map)
{
	int i;

	i = 0;
	if (check_coord(map, all_fig_coord) == -1 && check_param(all_fig_coord->x) + 1 <= map->sqr_size)
		while (i <= 3)
			all_fig_coord->x[i++]++;
	else
	{
		move_x_back(all_fig_coord);
		return (-1);
	}
	return (1);
}

int			move_fig_y(t_struct *all_fig_coord, t_map *map)
{
	int i;

	i = 0;
	if (check_coord(map, all_fig_coord) == -1 && check_param(all_fig_coord->y) + 1 <= map->sqr_size)
		while (i <= 3)
			all_fig_coord->y[i++]++;
	else
		return (-1);
	return (1);
}

int		check_coord(t_map *map, t_struct *all_coord)
{
	int index;

	index = 0;
	while (index <= 3)
	{
		if (check_param(all_coord->x) > map->sqr_size ||
			check_param(all_coord->y) > map->sqr_size)
			return (-1);
		if (map->map_arr[all_coord->y[index]][all_coord->x[index]] == '.')
			index++;
		else
			return (-1);
	}
	return (1);
}

int		del_one_fig(t_map *map, t_struct *all_fig)
{
	int i;

	i = 0;
	if (check_coord(map, all_fig) == -1)
		return (-1);
	while (i < 4)
	{
		map->map_arr[all_fig->y[i]][all_fig->x[i]] = '.';
		i++;
	}
	return (1);
}
