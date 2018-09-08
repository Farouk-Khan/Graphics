/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 13:15:27 by fkhan             #+#    #+#             */
/*   Updated: 2018/08/03 09:31:51 by fkhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft/includes/libft.h"
# include <mlx.h>
# include <libc.h>

typedef struct  s_window
{
    void        *display_link;
    void        *win;
}               t_window;

typedef struct  s_draw
{
    int colour;
    int x;
    int x1;
    int x2;
    int y;
    int y1;
    int y2;
    int Dx;
    int Dy;
    int xincr;
    int yincr;
}               t_draw;

typedef struct  s_display
{
    int         i;
    int         j;
    float       map_width;
    float       map_length;
    float       ratio;
    float       av_height;
    int         size;
    int         window_height;
    int         x;
    int         y;
    float       x_start;
    int         y_start;
}               t_display;

int		ft_exit(int key);
int     arr_size_2d(char **arr);
int     arr_size_3d(char ***arr);
char    ***memalloc_arr(char *file);
void    draw_down(t_window *win_struct, t_draw *draw_struct);
void    draw_up(t_window *win_struct, t_draw *draw_struct);
void draw_line(t_window *win_struct, t_draw *draw_struct);
float   average_height(char ***buffer);
void    set_map(t_display *display_struct, int win_width, int border, char ***map);
void    draw_width(t_display *display_struct, t_window *win_struct,  t_draw *draw_struct, char ***map);
void    draw_map(t_display *display_struct, t_window *win_struct,  t_draw *draw_struct, char ***map);
void    display_map(int win_width, int border, char ***map, char *map_name);
char    ***map_arr(char *map);

#endif
