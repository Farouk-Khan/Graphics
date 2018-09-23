/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wolf3D.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 16:37:40 by fkhan             #+#    #+#             */
/*   Updated: 2018/09/23 23:12:44 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Wolf3D_H
# define Wolf3D_H

# include "libft/includes/libft.h"
# include <mlx.h>
# include <libc.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# define WIDTH 1000
# define HEIGHT 500
# define MOVE 0.5
# define ROT 0.1

/*typedef struct 	s_map
{
	float		dx;
	float		dy;
	float		step;
	int			i;
	float		j;
	void 		*mlx;
	void		*win;
	int			y;
	char		***map;
	char		*line;
	int			fd;
}				t_map;*/

typedef struct	s_pos
{
	double		posX;
	double		posY;
	double		dirX;
	double		dirY;
	double		planeX;
	double		planeY;
	double		cameraX;
	double		rayDirX;
	double		rayDirY;
	int			mapX;
	int			mapY;
	double		sideDistX;
	double		sideDistY;
	double		deltaDistX;
	double		deltaDistY;
	double		perpWallDist;
	int			stepX;
	int			stepY;
	int			hit;
	int			side;
	int			h;
	int			lineHeight;
	int			drawStart;
	int			drawEnd;
	int			colour;
	int			x;
	int			moveUp;
	float		dx;
	float		dy;
	float		step;
	int			i;
	float		j;
	void 		*mlx;
	void		*win;
	int			y;
	char		***map;
	char		*line;
	int			fd;

}				t_pos;

/*typedef struct 	s_map
{
	float		dx;
	float		dy;
	float		step;
	int			i;
	float		j;
	void 		*mlx;
	void		*win;
	int			y;
	char		***map;
	char		*line;
	int			fd;
}				t_map;
*/
#endif
