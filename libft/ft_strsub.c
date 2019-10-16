/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fserlut <fserlut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 06:15:19 by fserlut           #+#    #+#             */
/*   Updated: 2019/05/02 22:58:20 by fserlut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*s_sub;
	int		i;

	i = 0;
	if (s && len + 1 != 0)
	{
		s_sub = (char*)malloc(len + 1);
		if (s_sub == NULL)
			return (NULL);
		while (len-- > 0)
			s_sub[i++] = s[start++];
		s_sub[i] = '\0';
		return (s_sub);
	}
	return (NULL);
}
