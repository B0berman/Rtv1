/*
** aliasing.c for  in /home/walbec_h/rendu_tek1/Igraph/MUL_2014_rtv1
** 
** Made by hugo walbecq
** Login   <walbec_h@epitech.net>
** 
** Started on  Sun Mar 15 12:41:16 2015 hugo walbecq
** Last update Mon Mar 16 12:35:55 2015 hugo walbecq
*/

#include	<math.h>
#include	<stdlib.h>
#include	"include/rtv1.h"

void		init_alia(t_rtv *rtv, double x, double y)
{
  double	y1;
  double	z1;

  rtv->color = 0x000000;
  rtv->coord.xo = -1000;
  rtv->coord.yo = 0;
  rtv->coord.zo = 0;
  y1 = (WIN_X / 2) - x;
  z1 = (WIN_Y / 2) - y;
  rtv->coord.vx = (WIN_X / 2) / tan(30.0 * M_PI / 180);
  rtv->coord.vy = y1 - rtv->coord.yo;
  rtv->coord.vz = z1 - rtv->coord.zo;
}

void		my_aliasing(int x, int y, t_rtv *rtv)
{
  double	x1;
  double	y1;
  double	coef;
  int		i;
  int		*col;

  i = 0;
  col = malloc(sizeof(int) * (pow(rtv->aliasing, 2) + 1));
  coef = 1 / (double)rtv->aliasing;
  x1 = (x - 1) + coef;
  while (x1 <= x)
    {
      y1 = (y - 1) + coef;
      while (y1 <= y)
	{
	  init_alia(rtv, x1, y1);
	  my_calc(rtv);
	  col[i++] = rtv->color;
	  y1 += coef;
	}
      x1 += coef;
    }
  rtv->color = my_average(col, pow(rtv->aliasing, 2));
  free(col);
}
