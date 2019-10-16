/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fserlut <fserlut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 15:14:27 by fserlut           #+#    #+#             */
/*   Updated: 2019/10/16 14:49:04 by fserlut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		valid_grill_point_n(t_one_fig one_fig)
{
	int	i;
	int	grill;
	int	point;
	int bsn;

	i = 0;
	grill = 0;
	point = 0;
	bsn = 0;
	if (one_fig.fig[0] == '\n')
		return (0);
	while (one_fig.fig[i])
	{
		if (one_fig.fig[i] == '#')
			grill++;
		if (one_fig.fig[i] == '.')
			point++;
		if (one_fig.fig[i] == '\n')
			bsn++;
		i++;
	}
	if (point == 12 && grill == 4 && (bsn == 5 || bsn == 3))
		return (1);
	return (-1);
}

int		valid_figure(t_one_fig one_fig)
{
	int i;
	int c_sub;

	i = 0;
	c_sub = 0;
	if (!(valid_grill_point_n(one_fig) == 1))
		return (-1);
	while (one_fig.fig[i])
	{
		if (one_fig.fig[i] == '#')
		{
			if (one_fig.fig[i + 1] == '#')
				c_sub++;
			if (i != 0 && one_fig.fig[i - 1] == '#')
				c_sub++;
			if (i <= 13 && one_fig.fig[i + 5] == '#')
				c_sub++;
			if (i >= 5 && one_fig.fig[i - 5] == '#')
				c_sub++;
		}
		i++;
	}
	if (c_sub == 6 || c_sub == 8)
		return (1);
	return (-1);
}

int		check_param(int *coord)
{
	int i;
	int max;

	max = 0;
	i = 0;
	while (i <= 3)
	{
		if (coord[i] > max)
			max = coord[i];
		i++;
	}
	return (++max);
}
