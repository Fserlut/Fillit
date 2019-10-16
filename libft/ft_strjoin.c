/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fserlut <fserlut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 23:11:25 by fserlut           #+#    #+#             */
/*   Updated: 2019/04/27 20:10:26 by fserlut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*s_new;

	if (s1 && s2)
	{
		len = ft_strlen(s1) + ft_strlen(s2);
		s_new = ft_strnew(len);
		if (!(s_new == NULL))
		{
			ft_strcpy(s_new, s1);
			ft_strcat(s_new, s2);
			return (s_new);
		}
	}
	return (NULL);
}
