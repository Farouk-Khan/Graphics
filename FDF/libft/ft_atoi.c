/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 08:29:27 by fkhan             #+#    #+#             */
/*   Updated: 2018/06/25 11:14:29 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_atoi(char *str)
{
	int	i;
	int	hold;
	int	neg;

	i = 0;
	hold = 0;
	neg = 1;
	if (!(*str))
		return (0);
	while ((str[i] == ' ') || (str[i] >= 7 && str[i] <= 13))
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		hold = (hold * 10) + (int)str[i] - '0';
		i++;
	}
	return (hold * neg);
}
