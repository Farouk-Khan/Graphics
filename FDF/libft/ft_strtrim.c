/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 12:23:00 by fkhan             #+#    #+#             */
/*   Updated: 2018/06/26 07:33:51 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

static int		ft_size(char const *str, int size)
{
	while (str[size - 1] == ' ' || str[size - 1] == '\t'\
			|| str[size - 1] == '\n')
		size--;
	return (size);
}

static char		*ft_loop(char const *str, char *ptr, int i, int size)
{
	int j;

	j = 0;
	while (j < size)
	{
		ptr[j] = str[i + j];
		j++;
	}
	ptr[j] = '\0';
	return (ptr);
}

char			*ft_strtrim(char const *str)
{
	int		i;
	int		size;
	char	*ptr;

	i = 0;
	if (!(str))
		return (0);
	size = ft_strlen((char *)str);
	if (size > 0)
		size = ft_size(str, size);
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
	{
		size--;
		i++;
	}
	if (size < 0)
		size = 0;
	ptr = (char *)malloc(sizeof(char) * (size + 1));
	if (!ptr)
		return (0);
	ptr = ft_loop(str, ptr, i, size);
	return (ptr);
}
