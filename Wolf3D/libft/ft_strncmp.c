/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 13:40:36 by fkhan             #+#    #+#             */
/*   Updated: 2018/06/26 07:29:05 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_strncmp(char *s1, char *s2, unsigned int len)
{
	int				i;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	i = 0;
	if (len == 0)
		return (0);
	while ((i < len - 1) && ptr1[i] == ptr2[i]\
			&& ptr1[i] != '\0' && ptr2[i] != '\0')
	{
		i++;
	}
	return (ptr1[i] - ptr2[i]);
}
