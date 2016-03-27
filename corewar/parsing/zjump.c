/*
** zjump.c for zjump in /home/duhieu_b/CPE/CPE_2015_corewar/vm/parsing
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Mon Mar 21 22:56:42 2016 benjamin duhieu
** Last update Sat Mar 26 20:30:45 2016 marc brout
*/

#include "vm.h"
#include "my.h"

int		zjump(t_data *data, t_pc *i)
{
  short		jump_size;

  if (can_i_run(i, 20))
    return (0);
  if (i->carry)
    {
      jump_size = read_short_from_ram(data->ram, MM(i->reg[0] + 1));
      i->reg[0] = i->reg[0] + (jump_size % IDX_MOD);
      if ((int)i->reg[0] < 0)
	i->reg[0] = MEM_SIZE + (int)i->reg[0];
    }
  return (0);
}
