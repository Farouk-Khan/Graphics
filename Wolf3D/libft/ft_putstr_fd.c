/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 12:08:07 by fkhan             #+#    #+#             */
/*   Updated: 2018/06/26 07:21:32 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <unistd.h>

void	ft_putstr_fd(char const *str, int fd)
{
	if (!(str) || !(fd))
		return ;
	while (*str)
	{
		write(fd, str, 1);
		str++;
	}
}
