/*
** delta.c for  in /home/walbec_h/rendu_2014-2015/Igraph/MUL_2014_rtv1
** 
** Made by hugo walbecq
** Login   <walbec_h@epitech.net>
** 
** Started on  Mon Feb 23 11:32:49 2015 hugo walbecq
** Last update Sun Mar 15 17:09:16 2015 hugo walbecq
*/

#include	"include/rtv1.h"

void		delta_cone(t_rtv *rtv, double k1, double k2, int i)
{
  if (rtv->flag == 0)
    {
      if ((k1 < k2 && k1 > 0.00001 && k1 < rtv->coord.k) ||
	  (k1 > k2 && k2 < 0.00001 && k1 < rtv->coord.k))
	{
	  rtv->obj = i;
	  rtv->color = CONE;
	  rtv->coord.k = k1;
	}
      else if ((k2 < k1 && k2 > 0.00001 && k2 < rtv->coord.k) ||
	       (k2 > k1 && k1 < 0.00001 && k2 < rtv->coord.k))
	{
	  rtv->obj = i;
	  rtv->coord.k = k2;
	  rtv->color = CONE;
	}
    }
  else
    {
      if (k1 < k2 && k1 > 0.00001)
	rtv->coord.k = k1;
      else if (k2 < k1 && k2 > 0.00001)
	rtv->coord.k = k2;
    }
}

void		delta_sphe(t_rtv *rtv, double k1, double k2, int i)
{
  if (k1 < k2 && k1 < rtv->coord.k && k1 > 0.00001)
    {
      rtv->color = SPHERE;
      rtv->obj = i;
      rtv->coord.k = k1;
    }
  else if (k2 <= k1 && k2 < rtv->coord.k && k2 > 0.00001)
    {
      rtv->color = SPHERE;
      rtv->obj = i;
      rtv->coord.k = k2;
    }
}

void		delta_cyl(t_rtv *rtv, double k1, double k2, int i)
{
  if (rtv->flag == 0)
    {
      if ((k1 < k2 && k1 > 0.00001 && k1 < rtv->coord.k) ||
	  (k1 > k2 && k2 < 0.00001 && k1 < rtv->coord.k))
	{
	  rtv->color = CYLINDR;
	  rtv->obj = i;
	  rtv->coord.k = k1;
	}
      else if ((k2 < k1 && k2 > 0.00001 && k2 < rtv->coord.k) ||
	       (k2 > k1 && k1 < 0.00001 && k2 < rtv->coord.k))
	{
	  rtv->color = CYLINDR;
	  rtv->obj = i;
	  rtv->coord.k = k2;
	}
    }
  else
    {
      if (k1 < k2 && k1 > 0.00001)
	rtv->coord.k = k1;
      else if (k2 < k1 && k2 > 0.00001)
	rtv->coord.k = k2;
    }
}
