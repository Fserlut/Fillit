/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gutorres <gutorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 23:00:53 by fserlut           #+#    #+#             */
/*   Updated: 2019/10/19 21:21:48 by gutorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*src;

	if (!(src = (char *)malloc(size)))
		return (NULL);
	ft_bzero(src, size);
	return (src);
}
