/*
** fork.c for fork in /home/duhieu_b/CPE/CPE_2015_corewar/vm/parsing
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Mon Mar 21 22:58:14 2016 benjamin duhieu
** Last update Sat Mar 26 20:33:43 2016 marc brout
*/

#include "vm.h"

int			can_i_run(t_pc *i, int cycle)
{
  if (i->cycle)
    {
      i->cycle--;
      return (1);
    }
  if (!i->run && !i->cycle)
    {
      i->run = 1;
      i->cycle = cycle;
      return (1);
    }
  i->run = 0;
  return (0);
}

int			frk(t_data *data, t_pc *i)
{
  int			val;

  if (can_i_run(i, 800))
    return (0);
  val = i->reg[0] +
    (read_short_from_ram(data->ram, MM(i->reg[0] + 1)) % IDX_MOD);
  if (val < 0)
    val = MEM_SIZE + val;
  if (add_pc(i, MM(val), 0))
    return (1);
  i->reg[0] = MM(i->reg[0] + 3);
  return (0);
}
