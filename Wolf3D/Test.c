/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 12:24:50 by fkhan             #+#    #+#             */
/*   Updated: 2018/09/18 14:06:52 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <mlx.h>
//#include <stdio.h>
//#include <math.h>
//#include <time.h>
//#include <stdlib.h>
#include "Wolf3D.h"

/*int	worldMap[24][24] = 
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};*/

/*void ft_verline(int x1, int start, int end, int color, struc_t *line)
{
	float x, y, dx, dy, step;
	int i;
	
	dx = x1;
	dy = (end - start);
	if (fabs(dx) >= fabs(dy))
		step = fabs(dx);
	else
		step = fabs(dy);
	dx = dx / step;
	dy = dy / step;
	x = x1;
	y = start;
	i = 1;
	while (i <= step)
	{
		mlx_pixel_put(line->mlx, line->win, x, y, color);
		x = x + dx;
		y = y + dy;
		i = i + 1;
	}
}*/


int	Key(int key)
{
	printf("%d\n", key);
	if (key == 53)
		exit(0);
/*	if (key == 126)//UP key
		
	if (key == 125)//DOWN key

	if (key == 124)//Right key

	if (key == 123)//LEFT key
*/
	return(0);
}

int main(void)
{
	double posX = 22, posY = 12;
	double dirX = -1, dirY = 0;
	double planeX = 0, planeY = 0.66;
//	double time = 0;
//	double oldTime = 0;
	void *mlx;
	void *win;
	int x = 0;
	double width = 1000;

	int i = 0;
	int y = 0;
	char ***map;
	char *line;
	int fd = 0;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 1000, 400, "Test");// 512  384

	fd = open("wolf.fdf", O_RDONLY);
	map = (char ***)malloc(sizeof(char *) * 100);
	while ((get_next_line(fd, &line)) > 0)
	{
		map[i] = ft_strsplit(line, ' ');
		y = ft_count_words(line, ' ');
		i++;
	}
	map[i] = NULL;

	while (x < width)
	{
		//Rays position + Direction
		double cameraX = 2 * x / width - 1;//x-coord in camera space
		double rayDirX = dirX + planeX * cameraX;
		double rayDirY = dirY + planeY * cameraX;
		
		//which box map is in
		int mapX = posX;
		int mapY = posY;

		//lenght of ray to first x and y side
		double sideDistX;
		double sideDistY;

		//length from one x or y side to the next x or y side
		double deltaDistX = fabs(1 / rayDirX);
		double deltaDistY = fabs(1 / rayDirY);
		double perpWallDist;

		//direction to step in , x or y (+1 or -1)
		int stepX;
		int stepY;

		int hit = 0; //was there a wall hit?
		int side; //was a NS or EW wall hit?

		//calculate step and initial sideDist
		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - posX) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - posY) * deltaDistY;
		}

		//perform DDA
		while (hit == 0)
		{
			//jump to next square
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			//check if ray hits wall
			if (ft_atoi(map[mapX][mapY]) > 0)//worldMap[mapX][mapY] > 0)
				hit = 1;
		}
	
		ft_putstr("c");	
		// calcuate distance projected
		if (side == 0)
			perpWallDist = (mapX - posX + (1 - stepX) / 2) / rayDirX;
		else
			perpWallDist = (mapY - posY + (1 - stepY) / 2) / rayDirY;

		//calculate height of line
		int h = 300;
		int lineHeight = (int)(h / perpWallDist);

		//calculate lowest + highest pixel
		int drawStart = -lineHeight / 2 + h / 2;
		if (drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + h / 2;
		if (drawEnd >= h)
			drawEnd = h - 1;
		
		//wall colour
		int color = 0x00FF00FF;
		if (ft_atoi(map[mapX][mapY]) == 1)//worldMap[mapX][mapY] == 1)
			color = 0x00FFFF00;
		if (ft_atoi(map[mapX][mapY]) == 2)//worldMap[mapX][mapY] == 2)
			color = 0x843A29BB;
		if (ft_atoi(map[mapX][mapY]) == 3)//worldMap[mapX][mapY] == 3)
			color = 0x000000FF;

		//line drawer begin
		float x1, y, dx, dy, step;
		int i;
		
		dx = x;
		dy = (drawEnd - drawStart);
		if (fabs(dx) >= fabs(dy))
			step = fabs(dx);
		else
			step = fabs(dy);
		dx = dx / step;
		dy = dy / step;
		x1 = x;
		y = drawStart;
		i = 1;
		while (i <= step)
		{
			mlx_pixel_put(mlx, win, x1, y, color);
			//x1 = x1 + dx;
			y = y + dy;
			i = i + 1;
		}
		//line drawer end
		x++;
	}
// 	oldTime = time;
//    time = clock();
//    double frameTime = (time - oldTime) / 1000.0; //frameTime is the time this frame has taken, in seconds
    //printf("%lf" (1.0 / frameTime)); //FPS counter
//	double moveSpeed = frameTime * 5.0; //the constant value is in squares/second
//    double rotSpeed = frameTime * 3.0; //the constant value is in radians/second

//	if (key == 126)//UP key
//	{
//		if (worldMap[(posX + dirX * moveSpeed)][(posY)] == false)
//			posX -= dirX * moveSpeed;
//		if (worldMap[(posX)][(posY + dirY * moveSpeed)] == false)
//			posY += dirY * moveSpeed;
//	}
	//if (key == 125)//DOWN key

	//if (key == 124)//Right key

	//if (key == 123)//LEFT key

	mlx_key_hook(win, Key, 0);
	mlx_loop(mlx);
}
