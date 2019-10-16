/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fserlut <fserlut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 06:39:18 by fserlut           #+#    #+#             */
/*   Updated: 2019/04/24 15:45:34 by fserlut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src,
					int c, size_t n)
{
	unsigned char *ptr;
	unsigned char *ptr1;

	ptr = (unsigned char*)dst;
	ptr1 = (unsigned char*)src;
	while (n-- > 0)
	{
		if (*ptr1 == (unsigned char)c)
		{
			*ptr = *ptr1;
			return (++ptr);
		}
		else
			*ptr++ = *ptr1++;
	}
	return (NULL);
}
