/*
** my_put_nbr.c for my_put_nbr in ~/rendu/Piscine_C_J10
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Mon Oct 12 19:37:45 2015 marc brout
** Last update Tue Mar 22 14:27:34 2016 marel_m
*/

#include <unistd.h>
#include "my.h"

void	my_putchar_error(char c)
{
  write(2, &c, 1);
}

int	my_put_nbr_error(int nb)
{
  int	power;
  int	stock;

  power = 1;
  if (nb < 0)
    {
      my_putchar_error('-');
      nb = -nb;
    }
  stock = nb;
  while ((nb / 10) > 0)
    {
      power = power * 10;
      nb = nb / 10;
    }
  while ((power / 10) > 0)
    {
      my_putchar_error((stock / power) + 48);
      stock = stock - ((stock / power) * power);
      power = power / 10;
    }
  my_putchar_error((stock % 10) + 48);
  return (0);
}
