/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 10:44:22 by fkhan             #+#    #+#             */
/*   Updated: 2018/06/26 07:31:10 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*ptr;
	size_t	i;

	i = size + 1;
	ptr = (char *)malloc(i);
	if (ptr == 0)
		return (0);
	ft_memset(ptr, '\0', i);
	return (ptr);
}
