/*
** main.c for  in /home/walbec_h/rendu_tek1/Igraph/MUL_2014_rtv1
** 
** Made by hugo walbecq
** Login   <walbec_h@epitech.net>
** 
** Started on  Sat Mar 14 11:57:16 2015 hugo walbecq
** Last update Sat May  9 13:32:33 2015 walbec_h
*/

#include	</usr/include/X11/X.h>
#include	<stdlib.h>
#include	<stdlib.h>
#include	<stdlib.h>
#include	"minilibx/mlx.h"
#include	"include/my.h"
#include	"include/rtv1.h"

void		inter_obj(t_rtv *rtv)
{
  int		i;

  rtv->flag = 0;
  i = 0;
  while (i < rtv->sph.here)
    inter_sphe(&rtv->coord, rtv, i++);
  i = 0;
  while (i < rtv->plan.here)
    inter_plan(&rtv->coord, rtv, i++);
  i = 0;
  while (i < rtv->cyl.here)
    inter_cyl(&rtv->coord, rtv, i++);
  i = 0;
  while (i < rtv->cone.here)
    inter_cone(&rtv->coord, rtv, i++);
  if (rtv->color == 16711680)
    rtv->color = SPHERE;
}

int		my_calc(t_rtv *rtv)
{
  t_coord	light;
  int		ret;

  rtv->obj = 0;
  rtv->coord.k = 10000;
  inter_obj(rtv);
  light.xo = rtv->coord.xo + (rtv->coord.k * rtv->coord.vx);
  light.yo = rtv->coord.yo + (rtv->coord.k * rtv->coord.vy);
  light.zo = rtv->coord.zo + (rtv->coord.k * rtv->coord.vz);
  rtv->coord.p[0] = light.xo;
  rtv->coord.p[1] = light.yo;
  rtv->coord.p[2] = light.zo;
  ret = rtv->color;
  if (rtv->color == PLAN && rtv->obj == 0)
    my_lady(rtv, &light);
  if (rtv->spot.here != 0 && rtv->coord.k != 10000)
    {
      my_light(rtv, &light);
      if (rtv->coord.k != 10000)
      	my_shadow(&light, rtv);
    }
  return (ret);
}

void		make_image(t_rtv *rtv)
{
  int		x;
  int		y;
  int		ret;

  y = 0;
  while (y <= WIN_Y)
    {
      x = 0;
      while (x <= WIN_X)
        {
	  init_image(rtv, x, y);
          ret = my_calc(rtv);
	  my_reflexion(rtv, ret);
	  if (x > 0 && y > 0 && x < WIN_X && y < WIN_Y &&
	      rtv->aliasing != 0)
	    my_aliasing(x, y, rtv);
          my_pixel_put_to_image(rtv, x, y);
          x++;
        }
      y++;
      mlx_put_image_to_window(rtv->mlx_ptr, rtv->win_ptr,
			      rtv->img_ptr, 0, 0);
    }
  my_putstr("Image done\n");
}

int		my_init(t_rtv *rtv)
{
  if ((rtv->mlx_ptr = mlx_init()) == NULL)
    return (1);
  rtv->color = 0x000000;
  rtv->img_ptr = mlx_new_image(rtv->mlx_ptr, WIN_X, WIN_Y);
  rtv->win_ptr = mlx_new_window(rtv->mlx_ptr, WIN_X, WIN_Y, "rtv1");
  rtv->data = mlx_get_data_addr(rtv->img_ptr, &rtv->bpp,
				&rtv->size_line, &rtv->endian);
  return (0);
}

int		main(int ac, char **av)
{
  t_rtv		rtv;

  if (ac == 2 && av[1][0] > '1' && av[1][0] <= '9')
    rtv.aliasing = av[1][0] - 48;
  else
    rtv.aliasing = 0;
  if ((my_init(&rtv)) == 1)
    return (0);
  if ((check_place(&rtv) == 1))
    return (0);
  make_image(&rtv);
  mlx_key_hook(rtv.win_ptr, gere_key, &rtv);
  mlx_expose_hook(rtv.win_ptr, gere_expose, &rtv);
  mlx_loop(rtv.mlx_ptr);
  return (0);
}
