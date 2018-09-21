/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 09:41:12 by fkhan             #+#    #+#             */
/*   Updated: 2018/06/25 11:19:19 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>
#include <stdio.h>

static char				*ft_nbrstr(int n, char *str, unsigned int pos)
{
	unsigned int	nb;

	pos--;
	if (n < 0)
	{
		nb = -n;
		str[0] = '-';
	}
	else
		nb = n;
	if (nb >= 10)
	{
		ft_nbrstr((nb / 10), str, pos);
		str[pos] = ((nb % 10) + '0');
	}
	else
		str[pos] = (nb + '0');
	return (str);
}

static unsigned int		ft_lennbr(int n)
{
	unsigned int	count;
	unsigned int	nb;

	count = 0;
	if (n < 0)
	{
		nb = (unsigned int)-n;
		count++;
	}
	else
		nb = (unsigned int)n;
	while (nb > 0)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}

char					*ft_itoa(int n)
{
	unsigned int	len;
	char			*ptr;

	len = ft_lennbr(n);
	if (n == 0)
	{
		ptr = ft_strnew(1);
		if (ptr == 0)
			return (NULL);
		ptr[0] = '0';
	}
	else
	{
		ptr = ft_strnew(len);
		if (ptr == 0)
			return (NULL);
		ptr = ft_nbrstr(n, ptr, len);
	}
	return (ptr);
}
