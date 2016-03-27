/*
** get_hight_score.c for tetris
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Thu Mar 17 11:04:39 2016 marc brout
** Last update Mon Mar 21 23:57:27 2016 marc brout
*/

#include <unistd.h>

void		my_putnbr_tofd(int nb, int fd)
{
  int		power;
  int		stock;
  char		c;

  power = 1;
  if (nb < 0)
    {
      write(fd, "-", 1);
      nb = -nb;
    }
  stock = nb;
  while ((nb / 10) > 0)
    {
      power *= 10;
      nb /= 10;
    }
  while ((power / 10) > 0)
    {
      c = (stock / power) + 48;
      write(fd, &c, 1);
      stock = stock - ((stock / power) * power);
      power /= 10;
    }
  c = (stock % power) + 48;
  write(fd, &c, 1);
}
