/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fserlut <fserlut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 17:10:37 by fserlut           #+#    #+#             */
/*   Updated: 2019/10/19 21:39:08 by fserlut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			print_map(t_struct_map new_map)
{
	int	i;
	int	j;

	i = 0;
	while (i < new_map.sqr_size)
	{
		j = 0;
		while (j < new_map.sqr_size)
		{
			ft_putchar(new_map.map_arr[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

t_struct_map	*create_map(int square_s)
{
	t_struct_map	*map_list;
	int				i;

	i = 0;
	if (!(map_list = (t_struct_map *)ft_memalloc(sizeof(t_struct_map))))
	{
		ft_memdel((void*)&map_list);
		return (NULL);
	}
	map_list->sqr_size = square_s;
	if (!(map_list->map_arr = \
		(char **)ft_memalloc(sizeof(char *) * map_list->sqr_size)))
		return (NULL);
	while (i < map_list->sqr_size)
	{
		map_list->map_arr[i] = ft_strnew(map_list->sqr_size);
		ft_memset(map_list->map_arr[i], '.', map_list->sqr_size);
		i++;
	}
	return (map_list);
}

t_struct_map	*free_old_map_cr_new(t_struct_map *old_map, int sq_s)
{
	t_struct_map	*new_map;

	new_map = create_map(sq_s);
	ft_memdel((void*)old_map->map_arr);
	ft_memdel((void*)&old_map);
	return (new_map);
}
