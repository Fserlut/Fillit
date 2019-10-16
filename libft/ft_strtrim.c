/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fserlut <fserlut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 00:34:30 by fserlut           #+#    #+#             */
/*   Updated: 2019/07/08 22:17:05 by fserlut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strtrim(char const *s)
{
	int			i_end;
	int			i_start;
	char		*s_new;

	if (s)
	{
		i_start = 0;
		i_end = ft_strlen(s) - 1;
		while ((s[i_start] == ' ' || s[i_start] == '\t' ||
				s[i_start] == '\n') && (s[i_start]))
			i_start++;
		while ((s[i_end] == ' ' || s[i_end] == '\t' ||
				s[i_end] == '\n') && (i_end > i_start))
			i_end--;
		if ((s_new = ft_strsub(s, i_start, i_end - i_start + 1)) == NULL)
			return (NULL);
		return (s_new);
	}
	return (NULL);
}
