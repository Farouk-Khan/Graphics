/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 12:40:16 by fkhan             #+#    #+#             */
/*   Updated: 2018/06/25 11:23:47 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *)dst;
	s2 = (unsigned char *)src;
	i = 0;
	if (s2 < s1)
	{
		i = len;
		while (i > 0)
		{
			i--;
			(s1[i]) = (s2[i]);
		}
	}
	else
	{
		while (i < len)
		{
			(s1[i]) = (s2[i]);
			i++;
		}
	}
	return (s1);
}
