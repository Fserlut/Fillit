/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fserlut <fserlut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 23:56:36 by fserlut           #+#    #+#             */
/*   Updated: 2019/05/04 00:35:40 by fserlut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_count_word(char *s, char l)
{
	int		i;
	int		c_word;

	c_word = 0;
	i = 0;
	while (s[i])
	{
		if ((ft_isalpha(s[i])) && ((s[i - 1] == l) || (i == 0)))
		{
			c_word++;
			i++;
		}
		else
			i++;
	}
	return (c_word + 1);
}
