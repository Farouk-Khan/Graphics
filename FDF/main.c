/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 00:32:31 by fkhan             #+#    #+#             */
/*   Updated: 2018/08/03 08:49:41 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	int		i;
	int		win_width;
	int		border;
	char	****arr_maps;

	if (argc > 1)
	{
		win_width = 1000;
		border = 50;
		i = 0;
		arr_maps = (char ****)malloc(sizeof(char *) * argc);
		while (argv[i + 1])
		{
			arr_maps[i] = map_arr(argv[i + 1]);
			i++;
		}
		arr_maps[i] = NULL;
		i = -1;
		while (arr_maps[++i])
			display_map(win_width, border, arr_maps[i], argv[i + 1]);
	}
	else
		ft_putstr("Please enter Maps as paramaters..\n");
	return (0);
}
