/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 14:10:34 by fkhan             #+#    #+#             */
/*   Updated: 2018/06/26 07:27:15 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *str, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*ptr;

	i = 0;
	if (str == 0 || f == 0)
		return (0);
	ptr = ft_strnew(ft_strlen((char *)str));
	if (ptr == 0)
		return (0);
	while (str[i] != '\0')
	{
		ptr[i] = f(i, str[i]);
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
