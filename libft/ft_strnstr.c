/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fserlut <fserlut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 02:08:40 by fserlut           #+#    #+#             */
/*   Updated: 2019/05/04 00:20:21 by fserlut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	len_needle;
	int		i;

	i = 0;
	len_needle = ft_strlen(needle);
	if (len_needle == '\0')
		return ((char*)haystack);
	while (haystack[i] != '\0' && i <= (int)(len - len_needle))
	{
		if (haystack[i] == needle[0])
			if (!ft_strncmp(haystack + i, needle, len_needle))
				return ((char*)(haystack + i));
		i++;
	}
	return (NULL);
}
