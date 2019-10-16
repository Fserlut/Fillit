/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fserlut <fserlut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 21:17:07 by fserlut           #+#    #+#             */
/*   Updated: 2019/10/08 16:29:07 by fserlut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_sqrt(int nbr)
{
	int	sqrt;

	sqrt = 1;
	if (nbr == 1)
		return (1);
	if (nbr < 0)
		return (0);
	while (sqrt * sqrt < nbr)
		sqrt++;
	return (sqrt);
}
