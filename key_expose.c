/*
** key_expose.c for  in /home/walbec_h/rendu_tek1/Igraph/TP_RT/copie de rtv1
** 
** Made by hugo walbecq
** Login   <walbec_h@epitech.net>
** 
** Started on  Fri Mar 13 15:46:52 2015 hugo walbecq
** Last update Fri Mar 13 15:46:53 2015 hugo walbecq
*/

#include	<stdlib.h>
#include	<math.h>
#include	"include/rtv1.h"
#include	"minilibx/mlx.h"

void		init_image(t_rtv *rtv, int x, int y)
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

void		my_lady(t_rtv *rtv, t_coord *light)
{
  int		x;
  int		y;

  x = (int)light->xo;
  y = (int)light->yo;
  if (y > 0)
    y += 50;
  if (x < 0)
    x = -x;
  if (y < 0)
    y = -y;
  if (rtv->plan.tab[0][3] == 0 && rtv->plan.tab[0][4] == 0 &&
      rtv->plan.tab[0][5] == 0)
    if ((x % 100 > 50 && y % 100 > 50) ||
	(x % 100 < 50 && y % 100 < 50))
      rtv->color = 0x00896D;
}

int		gere_key(int key, t_rtv *rtv)
{
  if (key == 65307)
    {
      rtv->color = 0;
      exit(1);
    }
  return (0);
}

int		gere_expose(t_rtv *rtv)
{
  mlx_put_image_to_window(rtv->mlx_ptr, rtv->win_ptr,
                          rtv->img_ptr, 0, 0);
  return (0);
}
