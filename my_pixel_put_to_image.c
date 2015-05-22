/*
** my_pixel_put_to_image.c for  in /home/walbec_h/rendu 2014-2015/Igraph/MUL_2014_rtv1
** 
** Made by hugo walbecq
** Login   <walbec_h@epitech.net>
** 
** Started on  Mon Feb  2 14:05:57 2015 hugo walbecq
** Last update Sun Feb 22 13:31:14 2015 hugo walbecq
*/

#include	"minilibx/mlx.h"
#include	"include/rtv1.h"

int		my_pixel_put_to_image(t_rtv *rtv, int x, int y)
{
  int		locate;
  int		a;

  locate = (rtv->size_line * y) + (x * rtv->bpp / 8);
  a = mlx_get_color_value(rtv->mlx_ptr, rtv->color);
  rtv->data[locate] = a & 255;
  rtv->data[locate + 1] = a >> 8 & 255;
  rtv->data[locate + 2] = a >> 16 & 255;
  return (0);
}
