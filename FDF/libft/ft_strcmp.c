/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 13:14:34 by fkhan             #+#    #+#             */
/*   Updated: 2018/06/26 07:22:59 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_strcmp(char *s1, char *s2)
{
	int				i;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	i = 0;
	while ((ptr1[i] != '\0' && ptr2[i] != '\0' && ptr1[i] == ptr2[i]))
	{
		i++;
	}
	return (ptr1[i] - ptr2[i]);
}
