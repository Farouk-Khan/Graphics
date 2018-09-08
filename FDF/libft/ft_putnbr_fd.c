/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 08:46:44 by fkhan             #+#    #+#             */
/*   Updated: 2018/06/26 07:21:10 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int hold;

	hold = n;
	if (n < 0)
	{
		hold = hold * (-1);
		ft_putchar_fd('-', fd);
	}
	if (hold > 9)
	{
		ft_putnbr_fd(hold / 10, fd);
		ft_putnbr_fd(hold % 10, fd);
	}
	else
		ft_putchar_fd(hold + 48, fd);
}
