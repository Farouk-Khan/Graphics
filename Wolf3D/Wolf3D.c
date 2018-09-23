/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wolf3D.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 16:19:23 by fkhan             #+#    #+#             */
/*   Updated: 2018/09/24 00:24:47 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Wolf3D.h"

int		keyCode(int key, t_pos *pos)
{
	if (key == 53)
	{
		ft_putstr(pos->map[(int)(pos->posX + pos->dirX * MOVE)][(int)(pos->posY)]);
		exit(0);
	}
	if (key == 126)//UP key
	{
		//pos->moveUp = 1;
		ft_putnbr(pos->posX);
	//	if (!(pos->map[(int)(pos->posX + pos->dirX * MOVE)][(int)(pos->posY)]))
	//	{
			ft_putstr("UP\n");
			pos->posX += pos->dirX * MOVE;
	//	}
		if (!(pos->map[(int)(pos->posX)][(int)(pos->posY + pos->dirY * MOVE)]))
		{
			ft_putstr("DOWN\n");
			pos->posY += pos->dirY * MOVE;
		}
	}
	if (key == 125)//DOWN key
	{
		if (!(pos->map[(int)(pos->posX - pos->dirX * MOVE)][(int)(pos->posY)]))
			pos->posX -= pos->dirX * MOVE;
		if (!(pos->map[(int)(pos->posX)][(int)(pos->posY - pos->dirY * MOVE)]))
			pos->posY -= pos->dirY * MOVE;
	}

	//if (key == 124)//Right key

	//if (key == 123)//LEFT key	
	return (0);
}

void	img(/*t_map *map,*/t_pos *pos)
{
	/*map->i*/pos->i = 1;
	/*map->dx*/pos->dx = pos->x;
	/*map->dy*/pos->dy = (pos->drawEnd - pos->drawStart);
	if (fabs(/*map*/pos->dx) >= fabs(/*map*/pos->dy))
		/*map*/pos->step = fabs(/*map*/pos->dx);
	else
		/*map*/pos->step = fabs(/*map*/pos->dy);
	/*map*/pos->dy = /*map*/pos->dy / /*map*/pos->step;
	/*map*/pos->j = pos->drawStart;
	while(/*map*/pos->i <= /*map*/pos->step)
	{
		mlx_pixel_put(/*map*/pos->mlx, /*map*/pos->win, pos->x, /*map*/pos->j, pos->colour);
		/*map->j = map->j + map->dy;*/pos->j += pos->dy;
		/*map->i = map->i + 1;*/pos->i += 1;
	}
}

void	colour(t_pos *pos/*, t_map *map*/)
{
	pos->colour = 0x00FF00FF;
	if (ft_atoi(/*map*/pos->map[pos->mapX][pos->mapY]) == 1)
		pos->colour = 0x00FFFF00;
	if (ft_atoi(/*map*/pos->map[pos->mapX][pos->mapY]) == 2)
		pos->colour = 0x843A29BB;
	if (ft_atoi(/*map*/pos->map[pos->mapX][pos->mapY]) == 3)
		pos->colour = 0x0000FFFF;
}

void	step_init(t_pos *pos)
{
	if (pos->rayDirX < 0)
	{
		pos->stepX = 1;//-1
		pos->sideDistX = (pos->posX - pos->mapX) * pos->deltaDistX;
	}
	else
	{
		pos->stepX = 1;//1
		pos->sideDistX = (pos->mapX + 1.0 - pos->posX) * pos->deltaDistX;
	}
	if (pos->rayDirY < 0)
	{
		pos->stepY = -1;//-1p
		pos->sideDistY = (pos->posY - pos->mapY) * pos->deltaDistY;
	}
	else
	{
		pos->stepY = -1;//1
		pos->sideDistY = (pos->mapY + 1.0 - pos->posY) * pos->deltaDistY;
	}
}

void	hitWall(t_pos *pos)
{

	ft_putstr("e1\n");

	if (pos->sideDistX < pos->sideDistY)
	{

		ft_putstr("e2\n");

		pos->sideDistX += pos->deltaDistX;
		pos->mapX += pos->stepX;
		pos->side = 0;
	}
	else
	{

		ft_putstr("e3\n");

		pos->sideDistY += pos->deltaDistY;
		pos->mapY += pos->stepY;
		pos->side = 1;
	}
	ft_putstr("e4\n");
}

void	inPos(t_pos *pos)//, t_map *map)
{
	pos->cameraX = 2 * pos->x / WIDTH - 1;
	pos->rayDirX = pos->dirX + pos->planeX * pos->cameraX;
	pos->rayDirY = pos->dirY + pos->planeY * pos->cameraX;	
	pos->mapX = pos->posX;
	pos->mapY = pos->posY;	
	pos->deltaDistX = fabs(1 / pos->rayDirX);
	pos->deltaDistY = fabs(1 / pos->rayDirY);
	step_init(pos);
	pos->hit = 0;

	ft_putstr("d\n");

	while (pos->hit == 0)
	{
//
		ft_putstr("e\n");

		hitWall(pos);

		ft_putstr("e5\n");
		ft_putstr("really\n");
		ft_putnbr(12);
	//	ft_putnbr(ft_atoi(map->map[pos->mapX][pos->mapY]));
		if (ft_atoi(/*map*/pos->map[pos->mapX][pos->mapY]) > 0) // ERROR IS HERE
			{
				ft_putstr("f\n");
				pos->hit = 1;
			}
	}

	ft_putstr("\nG\n");
	if (pos->side == 0)
	{
		ft_putstr("g\n");
		
		pos->perpWallDist = (pos->mapX - pos->posX + (1 - pos->stepX) / 2) / pos->rayDirX;
	}
	else
	{
		ft_putstr("h\n");

		pos->perpWallDist = (pos->mapX - pos->posY + (1 - pos->stepY) / 2) / pos->rayDirY;
	}	
//
	ft_putstr("\n");

	pos->lineHeight = (int)(pos->h / pos->perpWallDist);
	pos->drawStart = -(pos->lineHeight) / 2 + pos->h / 2;
	if (pos->drawStart < 0)
		pos->drawStart = 0;
	pos->drawEnd = pos->lineHeight / 2 + pos->h / 2;
	if (pos->drawEnd >= pos->h)
		pos->drawEnd = pos->h - 1;
}

void	read_init(/*t_map	*map*/t_pos *pos, char **av)
{
	int	fd;
	char *line;
	int i;

	i = 0;
	/*map*/pos->mlx = mlx_init();
	/*map*/pos->win = mlx_new_window(/*map*/pos->mlx, WIDTH, HEIGHT, "Wolf3D");
	ft_putstr(*av);
	ft_putstr("\n");
	fd = open(av[1], O_RDONLY);
	line = (char *)malloc(sizeof(char *) * 100);
	/*map*/pos->map = (char ***)malloc(sizeof(char *) * 100);
	while ((get_next_line(fd, &line)) > 0)
	{
		/*map*/pos->map[i] = ft_strsplit(line, ' ');
		/*map*/pos->y = ft_count_words(line, ' ');
		i++;
	}
	free(line);
	/*map*/pos->map[i] = NULL;
}

/*void	tme(t_map map, t_pos pos)
{
	oldTime = time;
	time = clock();
	frameTime = (time - oldTime) / 1000.0;
	moveSpeed = frameTime * 5.0;
	rotSpeed = frameTime * 3.0;
}*/

int		main(int ac, char **av)
{
//	t_map	map;
	t_pos	pos;	

	pos.posX = 9;
	pos.posY = 20;
	pos.dirX = -1;
	pos.planeX = 0;
	pos.planeY = 0.66;
	pos.h = 300;
	pos.moveUp = 0;
//
	ft_putstr("a\n");

	if (ac < 2)
	{
		write(1, "please enter a map\n", 20);
		return (0);
	}
	if (ac > 2)
	{
		write(1, "you have too many maps entered\n", 30);
		return (0);
	}
//
	ft_putstr("b\n");

	read_init(/*&map*/&pos, av);
	pos.x = 0;
	while (pos.x < WIDTH)
	{
//
		ft_putstr("c\n");

		inPos(&pos);//, &map);
		colour(&pos);//, &map);
		img(/*&map*/&pos);
		pos.x++;
	}
	mlx_key_hook(/*map*/pos.win, keyCode, &pos);
	mlx_loop(/*map*/pos.mlx);
	return (0);
}
