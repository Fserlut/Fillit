/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fserlut <fserlut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 19:24:33 by fserlut           #+#    #+#             */
/*   Updated: 2019/07/11 21:57:09 by fserlut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_range(int min, int max)
{
	int i;
	int *arr;

	i = 0;
	if (min >= max)
		return (NULL);
	arr = (int*)malloc(sizeof(*arr) * (max - min));
	if (arr == NULL)
		return (0);
	else
	{
		while (min < max)
		{
			arr[i] = min;
			min++;
			i++;
		}
	}
	return (arr);
}
