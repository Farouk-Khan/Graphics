/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 13:28:40 by fkhan             #+#    #+#             */
/*   Updated: 2018/06/25 11:21:51 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memchr(const void *str, int c, size_t len)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	d;

	d = (unsigned char)c;
	i = 0;
	if (!str)
		return (0);
	ptr = (unsigned char *)str;
	while (ptr[i] != d && i < (len - 1))
		i++;
	if (ptr[i] == d && len != 0)
	{
		ptr = ptr + i;
		return (ptr);
	}
	return (0);
}
