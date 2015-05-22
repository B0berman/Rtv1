/*
** my_strstr.c for  in /home/walbec_h/rendu 2014-2015/Igraph/MUL_2014_rtv1/my_lib
** 
** Made by hugo walbecq
** Login   <walbec_h@epitech.net>
** 
** Started on  Mon Feb  2 13:29:44 2015 hugo walbecq
** Last update Mon Feb  2 13:29:46 2015 hugo walbecq
*/

#include	<stdio.h>

char		*my_strstr(char *str, char *to_find)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (str[i] != '\0')
    {
      while (str[i] == to_find[j])
	{
	  j++;
	  if (to_find[j] == '\0')
	    {
	      i = i - (j - 1);
	      return (str + i);
	    }
	}
      i++;
    }
  return (NULL);
}
