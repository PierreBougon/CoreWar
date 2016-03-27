/*
** launch_match.c for corewar
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Tue Mar 22 15:44:56 2016 marc brout
** Last update Sun Mar 27 00:22:44 2016 marc brout
*/

#include "vm.h"
#include "my.h"

int		count_players_alive(t_champion *champ[4])
{
  int		i;
  int		total;

  i = 0;
  total = 0;
  while (i < 4)
    {
      if (champ[i]->alive >= 1)
	total += 1;
      i += 1;
    }
  return (total);
}

void		set_players(t_champion *champ[4])
{
  int		i;

  i = 0;
  while (i < 4)
    {
      if ((champ[i]->alive) >= 1)
	champ[i]->alive = 0;
      else
	champ[i]->alive = -1;
      i += 1;
    }
}

void		check_winner(t_data *data, t_champion *champ[4])
{
  int		i;

  if (data->last > 0)
    {
      i = -1;
      while (++i < 4)
	{
	  if (champ[i]->order == data->last)
	    {
	      my_printf("Le joueur %d %s à gagné\n", champ[i]->order,
			champ[i]->name);
	    }
	}
    }
}

void		copy_order_to_reg(t_champion *champ[4])
{
  int		i;

  i = 0;
  while (i < 4)
    {
      champ[i]->pc->reg[1] = champ[i]->order;
      i += 1;
    }
}

int		launch_match(t_data *data)
{
  data->nblive = 0;
  init_inst(data);
  set_players(data->champ);
  if (ready_to_cycle(data))
    return (1);
  check_winner(data, data->champ);
  return (0);
}
