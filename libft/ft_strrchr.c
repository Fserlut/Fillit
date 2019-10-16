/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fserlut <fserlut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 01:25:34 by fserlut           #+#    #+#             */
/*   Updated: 2019/05/03 02:50:17 by fserlut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *s_res;

	s_res = (char*)s;
	while (*s)
	{
		if (*s == c)
			s_res = (char*)s;
		s++;
	}
	if (*s_res == c)
		return (s_res);
	else if (c == '\0')
		return ((char*)s);
	return (NULL);
}
