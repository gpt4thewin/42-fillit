/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 00:40:49 by juazouz           #+#    #+#             */
/*   Updated: 2018/11/13 15:30:45 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	unsigned int	i;
	unsigned int	c1;
	unsigned int	c2;

	if (s1 == NULL || s2 == NULL)
		return (0);
	i = 0;
	while (s1[i] || s2[i])
	{
		c1 = s1[i];
		c2 = s2[i];
		if (c1 != c2)
		{
			return (0);
		}
		i++;
	}
	return (1);
}
