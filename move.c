/*
** moove.c for  in /home/walbec_h/rendu 2014-2015/Igraph/MUL_2014_rtv1
** 
** Made by hugo walbecq
** Login   <walbec_h@epitech.net>
** 
** Started on  Fri Feb  6 10:06:42 2015 hugo walbecq
** Last update Fri Mar 13 15:29:09 2015 hugo walbecq
*/

#include	<math.h>
#include	"include/rtv1.h"

void		translat(t_coord *coord, int x, int y, int z)
{
  static int	i = 0;

  if (i == 0)
    {
      coord->xo -= x;
      coord->yo -= y;
      coord->zo -= z;
      i++;
    }
  else
    {
      coord->xo += x;
      coord->yo += y;
      coord->zo += z;
      i--;
    }
}

void		rotate_x(double *y, double *z, int a)
{
  double	z1;
  double	y1;
  double	cosa;
  double	sina;

  cosa = cos(RAD(a));
  sina = sin(RAD(a));
  y1 = *y;
  z1 = *z;
  *y = cosa * y1 - sina * z1;
  *z = sina * y1 + cosa * z1;
}

void		rotate_z(double *x, double *y, int a)
{
  double	x1;
  double	y1;
  double	cosa;
  double	sina;

  cosa = cos(RAD(a));
  sina = sin(RAD(a));
  x1 = *x;
  y1 = *y;
  *x = cosa * x1 - sina * y1;
  *y = sina * x1 + cosa * y1;
}

void		rotate_y(double *x, double *z, int a)
{
  double	z1;
  double	x1;
  double	cosa;
  double	sina;

  cosa = cos(RAD(a));
  sina = sin(RAD(a));
  x1 = *x;
  z1 = *z;
  *x = cosa * x1 + sina * z1;
  *z = -sina * x1 + cosa * z1;
}

void		my_rotate(t_coord *coord, int x, int y, int z)
{
  static int	i = 0;

  if (i % 2 == 0)
    {
      rotate_x(&coord->vy, &coord->vz, -x);
      rotate_y(&coord->vx, &coord->vz, -y);
      rotate_z(&coord->vx, &coord->vy, -z);
      rotate_x(&coord->yo, &coord->zo, -x);
      rotate_y(&coord->xo, &coord->zo, -y);
      rotate_z(&coord->xo, &coord->yo, -z);
      i++;
    }
  else
    {
      rotate_x(&coord->vy, &coord->vz, x);
      rotate_y(&coord->vx, &coord->vz, y);
      rotate_z(&coord->vx, &coord->vy, z);
      rotate_x(&coord->yo, &coord->zo, x);
      rotate_y(&coord->xo, &coord->zo, y);
      rotate_z(&coord->xo, &coord->yo, z);
      i--;
    }
}
