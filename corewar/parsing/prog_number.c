/*
** prog_number.c for prog_number
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Mon Mar 21 20:22:13 2016 benjamin duhieu
** Last update Tue Mar 22 00:55:50 2016 marc brout
*/

#include "vm.h"

int		check_prog_number_value(t_data *data)
{
  int		i;

  i  = -1;
  while (++i < 4)
    if (data->champ[i]->order == -1)
      return (1);
  return (0);
}

void		put_order_in_champ(t_data *data, int nbr)
{
  int		i;

  i = -1;
  while (data->champ[++i]->order > 0);
  data->champ[i]->order = nbr;
}

void		recheck_prog_number(t_data *data)
{
  int	i;
  int	nbr;

  nbr = 0;
  while (check_prog_number_value(data))
    {
      i = -1;
      while (i < 3 && nbr != data->champ[++i]->order);
      if (i == 3)
	{
	  put_order_in_champ(data, nbr);
	}
      else
	nbr++;
    }
}
