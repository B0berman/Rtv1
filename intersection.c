/*
** intersection.c for  in /home/walbec_h/rendu 2014-2015/Igraph/MUL_2014_rtv1
** 
** Made by hugo walbecq
** Login   <walbec_h@epitech.net>
** 
** Started on  Thu Feb  5 11:12:32 2015 hugo walbecq
** Last update Sat May  9 13:19:43 2015 walbec_h
*/

#include	<math.h>
#include	"include/rtv1.h"

void		inter_sphe(t_coord *coord, t_rtv *rtv, int i)
{
  double	a;
  double	b;
  double	c;
  double	d;
  double	k2;
  double	k1;

  translat(coord, rtv->sph.tab[i][1],
	   rtv->sph.tab[i][2], rtv->sph.tab[i][3]);
  a = coord->vx * coord->vx + coord->vy * coord->vy + coord->vz * coord->vz;
  b = 2 * ((coord->xo * coord->vx) + (coord->yo * coord->vy)
	   + (coord->zo * coord->vz));
  c = pow(coord->xo, 2) + pow(coord->yo, 2) + pow(coord->zo, 2) -
    pow(rtv->sph.tab[i][0], 2);
  d = pow(b, 2) - (4 * a * c);
  translat(coord, rtv->sph.tab[i][1],
	   rtv->sph.tab[i][2], rtv->sph.tab[i][3]);
  if (d >= 0)
    {
      k2 = (-b + sqrt(d)) / (2 * a);
      k1 = (-b - sqrt(d)) / (2 * a);
      delta_sphe(rtv, k1, k2, i);
    }
}

void		inter_plan(t_coord *coord, t_rtv *rtv, int i)
{
  double	k2;

  translat(coord, rtv->plan.tab[i][0],
	   rtv->plan.tab[i][1], rtv->plan.tab[i][2]);
  my_rotate(coord, rtv->plan.tab[i][3], rtv->plan.tab[i][4],
	    rtv->plan.tab[i][5]);
  k2 = 1000;
  if (coord->vz != 0)
    k2 = -(coord->zo / coord->vz);
  if (k2 > 0 && k2 < coord->k)
    {
      rtv->color = PLAN;
      coord->k = k2;
      rtv->obj = i;
    }
  my_rotate(coord, rtv->plan.tab[i][3], rtv->plan.tab[i][4],
	    rtv->plan.tab[i][5]);
  translat(coord, rtv->plan.tab[i][0],
	   rtv->plan.tab[i][1], rtv->plan.tab[i][2]);
}

void		inter_cyl(t_coord *coord, t_rtv *rtv, int i)
{
  double	a;
  double	b;
  double	c;
  double	d;
  double	k1;
  double	k2;

  translat(coord, rtv->cyl.tab[i][1], rtv->cyl.tab[i][2], rtv->cyl.tab[i][3]);
  rotate(coord, rtv->cyl.tab[i][4], rtv->cyl.tab[i][5],
	    rtv->cyl.tab[i][6]);
  a = pow(coord->vx, 2) + pow(coord->vy, 2);
  b = 2 * (coord->xo * coord->vx + coord->yo * coord->vy);
  c = pow(coord->xo, 2) + pow(coord->yo, 2) - pow(rtv->cyl.tab[i][0], 2);
  d = pow(b, 2) - (4 * a * c);
  translat(coord, rtv->cyl.tab[i][1], rtv->cyl.tab[i][2], rtv->cyl.tab[i][3]);
  rotate(coord, rtv->cyl.tab[i][4], rtv->cyl.tab[i][5],
	    rtv->cyl.tab[i][6]);
  if (d >= 0)
    {
      k1 = (-b - sqrt(d)) / (2 * a);
      k2 = (-b + sqrt(d)) / (2 * a);
      delta_cyl(rtv, k1, k2, i);
    }
}

void		move_cone(t_rtv *rtv, t_coord *coord, int i)
{
  translat(coord, rtv->cone.tab[i][1],
	   rtv->cone.tab[i][2], rtv->cone.tab[i][3]);
  rotate(coord, rtv->cone.tab[i][4], rtv->cone.tab[i][5],
	    rtv->cone.tab[i][6]);
}

void		inter_cone(t_coord *coord, t_rtv *rtv, int i)
{
  double	a;
  double	b;
  double	c;
  double	d;
  double	k2;
  double	k1;

  move_cone(rtv, coord, i);
  a = (pow(coord->vx, 2) + pow(coord->vy, 2))
    - pow(coord->vz, 2) * TAN(rtv->cone.tab[i][0]);
  b = 2 * ((coord->xo * coord->vx + coord->yo * coord->vy)
	   - ((coord->zo * coord->vz) * TAN(rtv->cone.tab[i][0])));
  c = (pow(coord->xo, 2) + pow(coord->yo, 2))
    - pow(coord->zo, 2) * TAN(rtv->cone.tab[i][0]);
  d = pow(b, 2) - (4 * a * c);
  move_cone(rtv, coord, i);
  if (d >= 0)
    {
      k1 = (-b - sqrt(d)) / (2 * a);
      k2 = (-b + sqrt(d)) / (2 * a);
      delta_cone(rtv, k1, k2, i);
    }
}
