/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 13:32:55 by fkhan             #+#    #+#             */
/*   Updated: 2018/06/26 07:26:51 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strmap(char const *str, char (*f)(char))
{
	int		i;
	char	*ptr;

	i = 0;
	if (str == 0 || f == 0)
		return (0);
	ptr = ft_strnew(ft_strlen((char *)str));
	if (ptr == 0)
		return (0);
	while (str[i] != '\0')
	{
		ptr[i] = f(str[i]);
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
