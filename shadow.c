/*
** shadow.c for  in /home/walbec_h/rendu_tek1/Igraph/MUL_2014_rtv1
** 
** Made by hugo walbecq
** Login   <walbec_h@epitech.net>
** 
** Started on  Mon Mar  2 14:42:38 2015 hugo walbecq
** Last update Sun Mar 15 21:16:36 2015 hugo walbecq
*/

#include	<stdlib.h>
#include	"include/rtv1.h"

void		rotate(t_coord *coord, int x, int y, int z)
{
  static int	i = 0;

  if (i % 2 == 0)
    {
      rotate_x(&coord->vy, &coord->vz, -x);
      rotate_y(&coord->vx, &coord->vz, -y);
      rotate_z(&coord->vx, &coord->vy, -z);
      i++;
    }
  else
    {
      rotate_x(&coord->vy, &coord->vz, x);
      rotate_y(&coord->vx, &coord->vz, y);
      rotate_z(&coord->vx, &coord->vy, z);
      i--;
    }
}

void		check_shadow(t_coord *light, t_rtv *rtv, t_color *rgb)
{
  int		i;

  rtv->coord.k = 10000;
  i = 0;
  while (i < rtv->sph.here)
    inter_sphe(light, rtv, i++);
  i = 0;
  while (i < rtv->cone.here)
    inter_cone(light, rtv, i++);
  i = 0;
  while (i < rtv->cyl.here)
    inter_cyl(light, rtv, i++);
  i = 0;
  while (i < rtv->plan.here)
    inter_plan(light, rtv, i++);
  if (rtv->coord.k > 0.00001 && rtv->coord.k < 1)
    {
      rgb->r *= rtv->coord.k;
      rgb->g *= rtv->coord.k;
      rgb->b *= rtv->coord.k;
    }
}

void		my_shadow(t_coord *light, t_rtv *rtv)
{
  int		x;
  t_union	uni;
  int		tmp_color;
  int		*color;

  x = 0;
  color = malloc(sizeof(int) * (rtv->spot.here + 1));
  tmp_color = rtv->color;
  while (x < rtv->spot.here)
    {
      rtv->flag = 1;
      uni.color = tmp_color;
      light->vx = rtv->spot.tab[x][0] - light->xo;
      light->vy = rtv->spot.tab[x][1] - light->yo;
      light->vz = rtv->spot.tab[x][2] - light->zo;
      check_shadow(light, rtv, &uni.rgb);
      color[x] = uni.color;
      x++;
    }
  rtv->color = my_average(color, rtv->spot.here);
  free(color);
}
