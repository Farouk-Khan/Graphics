/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 10:25:46 by fkhan             #+#    #+#             */
/*   Updated: 2018/06/26 07:25:20 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	int		h1;
	int		h2;
	char	*ptr;

	if (!(s1) || !(s2))
		return (0);
	h1 = ft_strlen((char *)s1);
	h2 = ft_strlen((char *)s2);
	i = h1 + h2;
	ptr = ft_strnew(i);
	if (ptr == 0)
		return (0);
	ft_strcpy(ptr, s1);
	ft_strcat(ptr, (char *)s2);
	return (ptr);
}
