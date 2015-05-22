/*
** my_strlen.c for  in /home/walbec_h/rendu 2014-2015/Igraph/MUL_2014_rtv1/my_lib
** 
** Made by hugo walbecq
** Login   <walbec_h@epitech.net>
** 
** Started on  Mon Feb  2 13:29:29 2015 hugo walbecq
** Last update Mon Feb  2 13:29:30 2015 hugo walbecq
*/

int	my_strlen(char *str)
{
  int	y;

  y = 0;
  while (str[y] != '\0')
    y++;
  return (y);
}
