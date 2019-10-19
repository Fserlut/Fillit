/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gutorres <gutorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 17:02:04 by fserlut           #+#    #+#             */
/*   Updated: 2019/10/19 17:53:09 by gutorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	move_fig_in_struct(t_struct *all_fig)
{
	int	i;

	while (is_null_pos(all_fig->x) == 1)
	{
		i = 0;
		while (i <= 3)
		{
			all_fig->x[i]--;
			i++;
		}
	}
	while (is_null_pos(all_fig->y) == 1)
	{
		i = 0;
		while (i <= 3)
		{
			all_fig->y[i]--;
			i++;
		}
	}
}

int		is_null_pos(int *coord)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (coord[i] == 0)
			return (0);
		i++;
	}
	return (1);
}
