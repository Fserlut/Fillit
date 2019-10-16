/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fserlut <fserlut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 22:51:53 by fserlut           #+#    #+#             */
/*   Updated: 2019/04/30 22:58:37 by fserlut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*s_new;

	if (!s || !f)
		return (NULL);
	s_new = ft_strnew(ft_strlen(s));
	if (!(s_new == NULL))
	{
		i = 0;
		while (s[i])
		{
			s_new[i] = (*f)(i, s[i]);
			i++;
		}
		return (s_new);
	}
	return (NULL);
}
