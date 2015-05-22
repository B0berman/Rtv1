/*
** light.c for  in /home/walbec_h/rendu 2014-2015/Igraph/MUL_2014_rtv1
** 
** Made by hugo walbecq
** Login   <walbec_h@epitech.net>
** 
** Started on  Mon Feb  9 09:58:15 2015 hugo walbecq
** Last update Sat May  9 13:41:02 2015 walbec_h
*/

#include	<stdlib.h>
#include	<math.h>
#include	"include/rtv1.h"

int		make_light_next(t_rtv *rtv, double cosa)
{
  t_union	uni;
  int		color;
  unsigned char	r;
  unsigned char	g;
  unsigned char	b;

  color = rtv->color * (1 - BRILL) + (0xFFFFFF) * BRILL;
  uni.color = color;
  r = uni.rgb.r;
  g = uni.rgb.g;
  b = uni.rgb.b;
  uni.rgb.r *= cosa;
  uni.rgb.g *= cosa;
  uni.rgb.b *= cosa;
  if (cosa < 0.000001)
    uni.color = 0x000000;
  if (uni.rgb.r < (r * AMBIANCE))
    uni.rgb.r = (r * AMBIANCE);
  if (uni.rgb.g < (g * AMBIANCE))
    uni.rgb.g = (g * AMBIANCE);
  if (uni.rgb.b < (b * AMBIANCE))
    uni.rgb.b = (b * AMBIANCE);
  return (uni.color);
}

void		check_obj(t_rtv *rtv, t_coord *light,
			  double norme[3])
{
  if (rtv->color == SPHERE)
    {
      norme[0] = light->xo - rtv->sph.tab[rtv->obj][1];
      norme[1] = light->yo - rtv->sph.tab[rtv->obj][2];
      norme[2] = light->zo - rtv->sph.tab[rtv->obj][3];
    }
  else if (rtv->color == CYLINDR)
    {
      my_rotate(light, rtv->cyl.tab[rtv->obj][4], rtv->cyl.tab[rtv->obj][5],
      		rtv->cyl.tab[rtv->obj][6]);
      norme[0] = light->xo - rtv->cyl.tab[rtv->obj][1];
      norme[1] = light->yo - rtv->cyl.tab[rtv->obj][2];
      my_rotate(light, rtv->cyl.tab[rtv->obj][4], rtv->cyl.tab[rtv->obj][5],
      		rtv->cyl.tab[rtv->obj][6]);
    }
  else if (rtv->color == CONE)
    {
      my_rotate(light, rtv->cone.tab[rtv->obj][4], rtv->cone.tab[rtv->obj][5],
      		rtv->cone.tab[rtv->obj][6]);
      norme[0] = light->xo - rtv->cone.tab[rtv->obj][1];
      norme[1] = light->yo - rtv->cone.tab[rtv->obj][2];
      my_rotate(light, rtv->cone.tab[rtv->obj][4], rtv->cone.tab[rtv->obj][5],
      		rtv->cone.tab[rtv->obj][6]);
    }
}

int		make_light(t_rtv *rtv, t_coord *light, double norme[3])
{
  double	cosa;
  double	n;

  n = sqrt(pow(norme[0], 2) + pow(norme[1], 2) + pow(norme[2], 2));
  norme[0] /= n;
  norme[1] /= n;
  norme[2] /= n;
  n = sqrt(pow(light->vx, 2) + pow(light->vy, 2) + pow(light->vz, 2));
  light->vx /= n;
  light->vy /= n;
  light->vz /= n;
  cosa = (light->vx * norme[0] + light->vy * norme[1]
	  + light->vz * norme[2]);
  return (make_light_next(rtv, cosa));
}

int		my_average(int *color, int nb_spot)
{
  t_union	tmp;
  t_union	res;
  int		r;
  int		g;
  int		b;
  int		i;

  i = 1;
  res.color = color[0];
  r = res.rgb.r;
  g = res.rgb.g;
  b = res.rgb.b;
  while (i < nb_spot)
    {
      tmp.color = color[i++];
      r += tmp.rgb.r;
      g += tmp.rgb.g;
      b += tmp.rgb.b;
    }
  if (nb_spot == 0)
    nb_spot++;
  res.rgb.r = r / nb_spot;
  res.rgb.g = g / nb_spot;
  res.rgb.b = b / nb_spot;
  return (res.color);
}

void		my_light(t_rtv *rtv, t_coord *light)
{
  int		x;
  int		*color;
  double	norme[3];

  x = 0;
  norme[0] = 0;
  norme[1] = 0;
  norme[2] = 50;
  if (rtv->color != PLAN && rtv->color != 0x00896D)
    norme[2] = 0;
  check_obj(rtv, light, norme);
  color = malloc(sizeof(int) * (rtv->spot.here + 1));
  while (x < rtv->spot.here)
    {
      light->vx = rtv->spot.tab[x][0] - light->xo;
      light->vy = rtv->spot.tab[x][1] - light->yo;
      light->vz = rtv->spot.tab[x][2] - light->zo;
      color[x++] = make_light(rtv, light, norme);
    }
  rtv->color = my_average(color, rtv->spot.here);
  free(color);
}
