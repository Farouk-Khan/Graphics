/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 00:38:16 by fkhan             #+#    #+#             */
/*   Updated: 2018/08/03 10:29:59 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_window *win_struct, t_draw *draw_struct)
{
	draw_struct->Dx = abs(draw_struct->x2 - draw_struct->x1);
	draw_struct->Dy = abs(draw_struct->y2 - draw_struct->y1);
	if (draw_struct->x1 < draw_struct->x2)
		draw_struct->xincr = 1;
	else
		draw_struct->xincr = -1;
	if (draw_struct->y1 < draw_struct->y2)
		draw_struct->yincr = 1;
	else
		draw_struct->yincr = -1;
	draw_struct->x = draw_struct->x1;
	draw_struct->y = draw_struct->y1;
	if (draw_struct->Dx > draw_struct->Dy)
		draw_down(win_struct, draw_struct);
	else
		draw_up(win_struct, draw_struct);
	mlx_pixel_put(win_struct->display_link, win_struct->win, draw_struct->x1,
			draw_struct->y1, draw_struct->colour);
	mlx_pixel_put(win_struct->display_link, win_struct->win, draw_struct->x2,
			draw_struct->y2, draw_struct->colour);
}
