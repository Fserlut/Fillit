/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fserlut <fserlut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 14:39:53 by fserlut           #+#    #+#             */
/*   Updated: 2019/10/16 20:16:40 by fserlut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include "libft/libft.h"

typedef struct s_struct
{
	int	x[4];
	int	y[4];
	int height;
	int width;
	char letter;
}				t_struct;

typedef struct
{
	char fig[22];
}				t_one_fig;

typedef struct
{
	char	**map_arr;
	int		sqr_size;
}				t_map;

int				open_file(t_struct *all_figure, char *name_file, int *n_figure);
void			find_cord_figure(t_struct *all_figure, t_one_fig one_fig, int n_figure);
int				put_fig_in_struct(t_struct *all_figure, char *buffer, int read_b, int *n_figure);
int				valid_grill_point_n(t_one_fig one_fig);
int				place_one_fig(t_map *map, t_struct *all_fig_coord, int *n_fig);
void			place_fig(t_map *map, t_struct *all_fig_coord, int c_fig);
void			move_fig_in_struct(t_struct *all_fig);
int				del_one_fig(t_map *map, t_struct *all_fig);
int				valid_figure(t_one_fig one_fig);
int				check_param(int *coord);
t_map			*create_map(int square_s);
void			print_map(t_map new_map);
int				is_null_pos(int *coord);
int				move_fig_x(t_struct *all_fig_coord, t_map *map);
int				check_coord(t_map *map, t_struct *all_coord);
t_map			*free_old_map_cr_new(t_map *old_map, int sq_s);
int				move_fig_y(t_struct *all_fig_coord, t_map *map);
void			move_x_back(t_struct *all_fig);

#endif
