/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fserlut <fserlut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 21:19:58 by fserlut           #+#    #+#             */
/*   Updated: 2019/04/30 22:57:31 by fserlut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*s_new;

	if (!s || !f)
		return (NULL);
	s_new = ft_strnew(ft_strlen(s));
	if (!(s_new == NULL))
	{
		i = 0;
		while (s[i])
		{
			s_new[i] = (*f)(s[i]);
			i++;
		}
		return (s_new);
	}
	return (NULL);
}
