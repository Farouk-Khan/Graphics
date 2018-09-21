/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 09:18:27 by fkhan             #+#    #+#             */
/*   Updated: 2018/06/26 07:33:30 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strsub(char const *str, unsigned int start, size_t len)
{
	size_t	i;
	char	*ptr;

	i = 0;
	if (!(str))
		return (0);
	ptr = ft_strnew(len);
	if (ptr == 0)
		return (0);
	while (i < len)
	{
		ptr[i] = str[i + start];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
