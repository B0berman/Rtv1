/*
** reflexion.c for  in /home/walbec_h/rendu_2014-2015/Igraph/MUL_2014_rtv1
** 
** Made by hugo walbecq
** Login   <walbec_h@epitech.net>
** 
** Started on  Thu Feb 26 11:07:52 2015 hugo walbecq
** Last update Sun Mar 15 17:00:52 2015 hugo walbecq
*/

#include	<math.h>
#include	"include/rtv1.h"

void		make_reflex(int col_obj, t_rtv *rtv)
{
  t_union	uni;
  t_union	reflex;
  unsigned char	r;
  unsigned char	g;
  unsigned char	b;

  uni.color = col_obj;
  reflex.color = rtv->color;
  r = reflex.rgb.r * REFLEX + uni.rgb.r * (1 - REFLEX);
  g = reflex.rgb.g * REFLEX + uni.rgb.g * (1 - REFLEX);
  b = reflex.rgb.b * REFLEX + uni.rgb.b * (1 - REFLEX);
  uni.rgb.r = r;
  uni.rgb.g = g;
  uni.rgb.b = b;
  rtv->color = uni.color;
}

void		check_ob(double n[3], int col, t_rtv *rtv, double p[3])
{
  if (col == SPHERE)
    {
      n[0] = p[0] - rtv->sph.tab[rtv->obj][1];
      n[1] = p[1] - rtv->sph.tab[rtv->obj][2];
      n[2] = p[2] - rtv->sph.tab[rtv->obj][3];
    }
  else if (col == CYLINDR)
    {
      n[0] = p[0] - rtv->cyl.tab[rtv->obj][1];
      n[1] = p[1] - rtv->cyl.tab[rtv->obj][2];
      n[2] = 0;
    }
  else if (col == CONE)
    {
      n[0] = p[0] - rtv->cone.tab[rtv->obj][1];
      n[1] = p[1] - rtv->cone.tab[rtv->obj][2];
      n[2] = 0;
    }
}

void		init_reflex(t_coord *coord, double p[3], double n[3])
{
  double	rx;
  double	ry;
  double	rz;
  double	nb;
  double	scalaire;

  nb = sqrt(pow(n[0], 2) + pow(n[1], 2) + pow(n[2], 2));
  n[0] /= nb;
  n[1] /= nb;
  n[2] /= nb;
  scalaire = (n[0] * coord->vx + n[1] * coord->vy + n[2] * coord->vz);
  rx = (-2 * n[0] * scalaire) + coord->vx;
  ry = (-2 * n[1] * scalaire) + coord->vy;
  rz = (-2 * n[2] * scalaire) + coord->vz;
  coord->xo = p[0];
  coord->yo = p[1];
  coord->zo = p[2];
  coord->vx = rx;
  coord->vy = ry;
  coord->vz = rz;
}

void		my_reflexion(t_rtv *rtv, int col)
{
  double	n[3];

  n[0] = 0;
  n[1] = 0;
  n[2] = 100;
  if (col == 42)
    {
      check_ob(n, col, rtv, rtv->coord.p);
      init_reflex(&rtv->coord, rtv->coord.p, n);
      col = rtv->color;
      my_calc(rtv);
      make_reflex(col, rtv);
    }
}
