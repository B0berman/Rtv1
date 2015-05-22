/*
** error_obj.c for  in /home/walbec_h/rendu_tek1/Igraph/MUL_2014_rtv1
** 
** Made by hugo walbecq
** Login   <walbec_h@epitech.net>
** 
** Started on  Sun Mar 15 16:04:05 2015 hugo walbecq
** Last update Sun Mar 15 16:29:29 2015 hugo walbecq
*/

#include	"include/rtv1.h"
#include	"include/my.h"

int		nb_argbis(char *buffer, int i)
{
  int		nb;

  nb = 0;
  while (buffer[i] != '\n')
    {
      if (buffer[i] == ';')
	nb++;
      i++;
    }
  return (nb);
}

int		message()
{
  my_putstr("Incorrect file : help in file 'manconf'\n");
  return (1);
}

int		check_arg_obj(char *buffer)
{
  int		i;
  int		a;

  a = 0;
  i = 0;
  while (buffer[i] != '\0')
    {
      if (buffer[i] == 'l' && buffer[i + 1] == 'i')
	if (nb_argbis(buffer, i) != 3)
	  a++;
      if (buffer[i] == 'p' && buffer[i + 1] == 'l')
	if (nb_argbis(buffer, i) != 6)
	  a++;
      if (buffer[i] == 's' && buffer[i + 1] == 'p')
	if (nb_argbis(buffer, i) != 4)
	  a++;
      if (buffer[i] == 'c' && buffer[i + 1] == 'y')
	if (nb_argbis(buffer, i) != 7)
	  a++;
      i++;
    }
  if (a != 0)
    return (message());
  return (0);
}
