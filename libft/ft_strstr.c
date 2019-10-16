/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fserlut <fserlut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 19:29:52 by fserlut           #+#    #+#             */
/*   Updated: 2019/04/26 01:16:04 by fserlut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int i2;

	i = 0;
	if (needle[0] == '\0')
		return ((char*)&haystack[0]);
	while (haystack[i] != '\0')
	{
		i2 = 0;
		while (haystack[i + i2] == needle[i2])
		{
			i2++;
			if (needle[i2] == '\0')
				return ((char*)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}
