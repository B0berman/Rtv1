/*
** find_obj.c for  in /home/walbec_h/rendu 2014-2015/Igraph/MUL_2014_rtv1
** 
** Made by hugo walbecq
** Login   <walbec_h@epitech.net>
** 
** Started on  Tue Feb  3 15:20:37 2015 hugo walbecq
** Last update Sun Mar 15 16:03:41 2015 hugo walbecq
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"include/rtv1.h"
#include	"include/my.h"

char		*find_number(char *buffer, int i)
{
  char		*res;
  int		a;
  int		b;

  a = i;
  b = 0;
  res = malloc(sizeof(char) * 9);
  while (buffer[a] != ';')
    res[b++] = buffer[a++];
  res[b] = '\0';
  return (res);
}

int		check_all(char *buffer)
{
  int		i;

  i = 0;
  while (buffer[i] != '\0')
    {
      if (buffer[i] != 's' && buffer[i] != 'p' && buffer[i] != ';' &&
	  buffer[i] != 'l' && buffer[i] != 'i' && buffer[i] != '-' &&
	  buffer[i] != 'c' && buffer[i] != 'y' && buffer[i] != '\n' &&
	  buffer[i] != 'o' && (buffer[i] < '0' || buffer[i] > '9'))
	{
	  my_putstr("Incorrect character: '");
	  my_putchar(buffer[i]);
	  my_putstr("' in file\n");
	  return (1);
	}
      i++;
    }
  return (0);
}

int		check_num(char *buffer, int i)
{
  if (buffer[++i] == ';')
    {
      my_putstr("Incorrect file : two ';' without numbers\n");
      return (1);
    }
  if (buffer[i] != '\n')
    while (buffer[i] != ';')
      {
	if (buffer[i] != '-' && (buffer[i] < '0' || buffer[i] > '9'))
	  {
	    my_putstr("Bad character(s) between two ';'\n");
	    return (1);
	  }
	i++;
      }
  if (check_arg_obj(buffer) == 1)
    return (1);
  return (0);
}

int		check_buff(char *buffer)
{
  int		i;

  i = 0;
  if (check_all(buffer) == 1)
    return (1);
  while (buffer[i] != '\0')
    {
      if (buffer[i] == '\n')
	if (buffer[i - 1] != ';')
	  {
	    my_putstr("Incorrect file (help in file 'manconf')\n");
	    return (1);
	  }
      if (buffer[i] == ';')
	if (check_num(buffer, i) == 1)
	  return (1);
      i++;
    }
  i--;
  if (buffer[i] != '\n')
    {
      my_putstr("You must put a 'backslash n' at the end of file\n");
      return (1);
    }
  return (0);
}
