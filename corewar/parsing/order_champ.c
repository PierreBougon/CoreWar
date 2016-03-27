/*
** order_champ.c for order in /CPE/CPE_2015_corewar/vm/parsing
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Mon Mar 21 21:08:10 2016 benjamin duhieu
** Last update Sat Mar 26 22:55:45 2016 benjamin duhieu
*/

#include "vm.h"

void		swap_champ(t_data *data, int i)
{
  t_champion	*tmp;

  tmp = data->champ[i];
  data->champ[i] = data->champ[i + 1];
  data->champ[i + 1] = tmp;
}

void		order_champ(t_data *data)
{
  int		i;
  int		a;

  i = -1;
  while (++i < 3)
    {
      a = data->champ[i]->order;
      if (a > data->champ[i + 1]->order)
	{
	  swap_champ(data, i);
	  i = -1;
	  continue ;
	}
    }
  copy_order_to_reg(data->champ);
}
