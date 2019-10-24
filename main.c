/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fserlut <fserlut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 15:08:09 by fserlut           #+#    #+#             */
/*   Updated: 2019/10/22 00:28:35 by fserlut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	t_struct		figure[26];
	t_struct_map	*new_map;
	int				n_figure;

	n_figure = 0;
	if (ac == 2)
	{
		if (open_file(&figure[0], av[1], &n_figure) == 1)
		{
			new_map = create_map(ft_sqrt(4 * n_figure));
			place_fig(new_map, &figure[0], n_figure);
			return (0);
		}
		else
		{
			ft_putendl("error");
			return (-1);
		}
	}
	else
		ft_putendl("usage: ./fillit input_file");
	return (-1);
}
