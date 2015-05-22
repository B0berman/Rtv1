/*
** my_put_nbr.c for  in /home/walbec_h/rendu 2014-2015/Igraph/MUL_2014_rtv1/my_lib
** 
** Made by hugo walbecq
** Login   <walbec_h@epitech.net>
** 
** Started on  Mon Feb  2 13:28:54 2015 hugo walbecq
** Last update Mon Feb  2 13:28:55 2015 hugo walbecq
*/

int	my_put_nbr(int nb)
{
  if ((nb < 10 && nb > 0) ||
      (nb > -10 && nb < 0) || nb == 0)
    {
      if (nb < 0)
        {
          my_putchar('-');
          my_putchar(-nb + 48);
        }
      else
        my_putchar(nb + 48);
    }
  else
    {
      my_put_nbr(nb / 10);
      if (nb > 0)
        my_putchar(nb % 10 + 48);
      else
        my_putchar(nb % 10 * -1 + 48);
    }
}
