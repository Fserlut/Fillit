/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gutorres <gutorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 14:39:53 by fserlut           #+#    #+#             */
/*   Updated: 2019/10/19 18:28:34 by gutorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include "libft/libft.h"

typedef	struct	s_map
{
	char		**map_arr;
	int			sqr_size;
}				t_struct_map;

typedef	struct	s_struct
{
	int			x[4];
	int			y[4];
	int			height;
	int			width;
	int			number;
	char		letter;
}				t_struct;

typedef	struct	s_fig
{
	char		fig[22];
}				t_struct_one_fig;

int				open_file(t_struct *all_figure, char *name_file, int *n_figure);
void			find_cord_figure(t_struct *all_figure, \
				t_struct_one_fig one_fig, int n_figure);
int				put_fig_in_struct(t_struct *all_figure, char *buffer, \
				int read_b, int *n_figure);
int				valid_grill_point_n(t_struct_one_fig one_fig);
int				place_one_fig(t_struct_map *map, t_struct *all_fig_coord, \
				int all_fig);
void			place_fig(t_struct_map *map, t_struct *all_fig_coord, \
				int c_fig);
void			move_fig_in_struct(t_struct *all_fig);
int				check_coord(t_struct_map *map, t_struct *f_depot, \
				int y_step, int x_step);
void			del_one_fig(t_struct_map *map, t_struct *all_coord, \
				int x_step, int y_step);
int				valid_figure(t_struct_one_fig one_fig);
int				check_param(int *coord);
t_struct_map	*create_map(int square_s);
void			print_map(t_struct_map new_map);
int				is_null_pos(int *coord);
t_struct_map	*free_old_map_cr_new(t_struct_map *old_map, int sq_s);

#endif
