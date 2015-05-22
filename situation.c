/*
** situation.c for  in /home/walbec_h/rendu 2014-2015/Igraph/MUL_2014_rtv1
** 
** Made by hugo walbecq
** Login   <walbec_h@epitech.net>
** 
** Started on  Tue Feb  3 14:41:40 2015 hugo walbecq
** Last update Sat Mar 14 12:33:34 2015 hugo walbecq
*/

#include	<fcntl.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	"include/rtv1.h"
#include	"include/my.h"

int		nb_obj(char *buffer)
{
  int		i;
  int		nb;

  nb = 0;
  i = 0;
  while (buffer[i] != '\0')
    {
      if (buffer[i] == '\n')
	nb++;
      i++;
    }
  return (nb);
}

int		nb_arg(char *buffer, int *i)
{
  int		nb;
  int		j;

  nb = 0;
  j = *i;
  while (buffer[j] != '\n' && buffer[j] != '\0')
    {
      if (buffer[j] == ';')
	nb++;
      j++;
    }
  return (nb);
}

int		*find_thing(int *i, char *buffer)
{
  int		j;
  int		*tab;

  j = 0;
  tab = malloc(sizeof(int) * (nb_arg(buffer, i) + 1));
  (*i) += 2;
  while (buffer[*i] != '\n')
    {
      if ((buffer[*i] >= '0' && buffer[*i] <= '9') || buffer[*i] == '-')
	tab[j++] = my_getnbr(find_number(buffer, *i));
      while (buffer[*i] != ';')
	(*i)++;
      (*i)++;
    }
  return (tab);
}

int		find_obj(char *buffer, t_rtv *rtv)
{
  int		i;

  i = 0;
  rtv->sph.tab = malloc(sizeof(int *) * (nb_obj(buffer) + 1));
  rtv->cyl.tab = malloc(sizeof(int *) * (nb_obj(buffer) + 1));
  rtv->cone.tab = malloc(sizeof(int *) * (nb_obj(buffer) + 1));
  rtv->plan.tab = malloc(sizeof(int *) * (nb_obj(buffer) + 1));
  rtv->spot.tab = malloc(sizeof(int *) * (nb_obj(buffer) + 1));
  while (buffer[i] != '\0')
    {
      if (buffer[i] == 's' && buffer[i + 1] == 'p')
	rtv->sph.tab[rtv->sph.here++] = find_thing(&i, buffer);
      else if (buffer[i] == 'p' && buffer[i + 1] == 'l')
	rtv->plan.tab[rtv->plan.here++] = find_thing(&i, buffer);
      else if (buffer[i] == 'c' && buffer[i + 1] == 'y')
	rtv->cyl.tab[rtv->cyl.here++] = find_thing(&i, buffer);
      else if (buffer[i] == 'c' && buffer[i + 1] == 'o')
	rtv->cone.tab[rtv->cone.here++] = find_thing(&i, buffer);
      else if (buffer[i] == 'l' && buffer[i + 1] == 'i')
	rtv->spot.tab[rtv->spot.here++] = find_thing(&i, buffer);
      i++;
    }
  return (0);
}

int		check_place(t_rtv *rtv)
{
  int		fd;
  int		nb;
  char		buffer[30000];

  rtv->sph.here = 0;
  rtv->cyl.here = 0;
  rtv->cone.here = 0;
  rtv->plan.here = 0;
  rtv->spot.here = 0;
  if ((fd = open("my_objects", O_RDWR)) == -1)
    return (1);
  nb = read(fd, buffer, 30000);
  close(fd);
  buffer[nb] = '\0';
  if (check_buff(buffer) == 1)
    return (1);
  if ((find_obj(buffer, rtv)) == 1)
    {
      my_putstr("There is nothing in this file\n");
      return (1);
    }
  return (0);
}
