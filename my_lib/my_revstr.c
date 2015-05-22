/*
** my_revstr.c for  in /home/walbec_h/rendu 2014-2015/Igraph/MUL_2014_rtv1/my_lib
** 
** Made by hugo walbecq
** Login   <walbec_h@epitech.net>
** 
** Started on  Mon Feb  2 13:29:20 2015 hugo walbecq
** Last update Mon Feb  2 13:29:21 2015 hugo walbecq
*/

char	*my_revstr(char *str)
{
  int	x;
  int	i;
  int	y;
  int	w;

  x = 0;
  i = 0;
  while (str[x] != '\0')
    x++;
  x--;
  while (i < x)
    {
      y = str[x];
      str[x] = str[i];
      str[i] = y;
      i++;
      x--;
    }
  return (str);
}
