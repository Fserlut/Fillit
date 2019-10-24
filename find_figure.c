/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_figure.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fserlut <fserlut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 19:01:32 by fserlut           #+#    #+#             */
/*   Updated: 2019/10/22 13:33:04 by fserlut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			open_file(t_struct *all_figure, char *name_file, int *n_figure)
{
	int			fd;
	int			ret;
	char		buff[546];

	if ((fd = open(name_file, O_RDONLY)) < 1)
		return (-1);
	if ((ret = read(fd, buff, 546)) < 1)
		return (-1);
	if ((put_fig_in_struct(all_figure, buff, ret, n_figure)) == -1)
		return (-1);
	else
		return (1);
}

void		find_cord_figure(t_struct *all_figure, \
				t_struct_one_fig one_fig, int n_figure)
{
	int			xy;
	int			i;

	i = 0;
	xy = 0;
	while (one_fig.fig[i])
	{
		if (one_fig.fig[i] == '#')
		{
			all_figure[n_figure].x[xy] = i % 5;
			all_figure[n_figure].y[xy] = i / 5;
			xy++;
		}
		i++;
	}
}

int			put_fig_in_struct(t_struct *all_figure, char *buffer, \
				int read_b, int *n_figure)
{
	int					i;
	t_struct_one_fig	*one_fig[read_b];

	i = 0;
	while (i <= read_b)
	{
		one_fig[*n_figure] = ft_memalloc(sizeof(t_struct_one_fig));
		ft_strncpy(one_fig[*n_figure]->fig, &buffer[i], 21);
		if (valid_figure(*one_fig[*n_figure]) != 1)
		{
			free((void*)one_fig[*n_figure]);
			return (-1);
		}
		find_cord_figure(all_figure, *one_fig[*n_figure], *n_figure);
		move_fig_in_struct(&all_figure[*n_figure]);
		all_figure[*n_figure].letter = 'A' + *n_figure;
		all_figure[*n_figure].height = check_param(all_figure[*n_figure].y);
		all_figure[*n_figure].width = check_param(all_figure[*n_figure].x);
		all_figure[*n_figure].number = *n_figure;
		i += 21;
		free((void*)one_fig[*n_figure]);
		(*n_figure)++;
	}
	return (1);
}
