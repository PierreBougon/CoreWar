/*
** my_bzero.c for corewar
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Mon Mar 21 13:44:11 2016 marc brout
** Last update Sat Mar 26 22:49:43 2016 benjamin duhieu
*/

#include "vm.h"

char		endianness()
{
  int		i;
  char		*x;

  i = 1;
  x = (char *)&i;
  return (x[0]);
}

int		swap_integer(int nb)
{
  int		ret;

  ret = ((nb >> 24) & 0xff) | ((nb <<8) & 0xff0000) |
    ((nb >> 8) & 0xff00) | ((nb << 24) & 0xff000000);
  return (ret);
}

void	my_bzero(void *var, int size, char val)
{
  int	i;
  char	*str;

  if (var)
    {
      i = 0;
      str = (char *)var;
      while (i < size)
	{
	  str[i] = val;
	  i += 1;
	}
    }
}
