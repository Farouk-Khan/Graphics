/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 11:01:58 by fkhan             #+#    #+#             */
/*   Updated: 2018/06/26 07:22:36 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_strclr(char *str)
{
	if (!(str))
		return ;
	while (*str != '\0')
	{
		*str = '\0';
		str++;
	}
}
