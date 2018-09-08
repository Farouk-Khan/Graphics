/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 09:32:51 by fkhan             #+#    #+#             */
/*   Updated: 2018/06/26 07:25:57 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t	ft_strlcat(char *s1, char *s2, size_t len)
{
	size_t		i;
	size_t		size;

	size = ft_strlen(s1) + ft_strlen(s2);
	if (len <= ft_strlen(s1))
		return (ft_strlen(s2) + len);
	while (*s1)
		s1++;
	i = 0;
	while ((i < len - (size - ft_strlen(s2)) - 1) && s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (size);
}
