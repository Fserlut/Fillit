/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fserlut <fserlut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 19:20:42 by fserlut           #+#    #+#             */
/*   Updated: 2019/07/11 00:29:45 by fserlut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	size_t	lenstr;

	if (!s)
		return (NULL);
	while (*s == c)
		++s;
	if (!(tab = (char**)malloc((ft_count_word((char*)s, c) + 1) *
		sizeof(char*))))
		return (NULL);
	i = 0;
	while (*s != '\0')
	{
		lenstr = 0;
		while (*s != c && *s != '\0' && ++s)
			++lenstr;
		if (!(tab[i] = ft_strnew(lenstr)))
			return (NULL);
		ft_strncpy(tab[i++], s - lenstr, lenstr);
		while (*s == c)
			++s;
	}
	tab[i] = NULL;
	return (tab);
}
