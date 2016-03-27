/*
** live-suv.c for live-sub in /CPE/CPE_2015_corewar/vm/parsing
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Mon Mar 21 21:40:56 2016 benjamin duhieu
** Last update Sat Mar 26 20:32:11 2016 marc brout
*/

#include "my.h"
#include "vm.h"

int	live(t_data *data, t_pc *i)
{
  int	chk;
  int	a;

  if (can_i_run(i, 10))
    return (0);
  chk = read_int_from_ram(data->ram, MM(i->reg[0] + 1));
  a = -1;
  while (++a < 4)
    {
      if (chk == (int)data->champ[a]->pc->reg[1])
	{
	  my_printf("Le joueur %d %s est en vie.\n",
	  	    data->champ[a]->order, data->champ[a]->name);
	  data->champ[a]->alive = 1;
	  data->last = data->champ[a]->order;
	}
    }
  data->nblive++;
  i->reg[0] = MM(i->reg[0] + 5);
  return (0);
}
