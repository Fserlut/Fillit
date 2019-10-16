/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fserlut <fserlut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 00:47:08 by fserlut           #+#    #+#             */
/*   Updated: 2019/04/27 14:50:28 by fserlut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	int			i;
	char		*s;

	i = 0;
	while (s1[i])
		i++;
	s = (char*)malloc(sizeof(char) * (i + 1));
	if (s == NULL)
		return (NULL);
	else
	{
		i = 0;
		while (s1[i])
		{
			s[i] = s1[i];
			i++;
		}
		s[i] = '\0';
	}
	return (s);
}
