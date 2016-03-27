/*
** aff.c for aff in /home/duhieu_b/CPE/CPE_2015_corewar/vm/parsing
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Mon Mar 21 23:01:53 2016 benjamin duhieu
** Last update Sat Mar 26 12:27:02 2016 marc brout
*/

#include <unistd.h>
#include "vm.h"

int		aff(t_data *data, t_pc *i)
{
  unsigned	first;
  char		c;

  if (can_i_run(i, 2))
    return (0);
  first = (data->ram[MM(i->reg[0] + 1)] >> 6) & (char)3;
  if (first != 1)
    return (0);
  if (data->ram[MM(i->reg[0] + 2)] < 1 ||
      data->ram[MM(i->reg[0] + 2)] > 16)
    return (0);
  c = ((unsigned)i->reg[(int)data->ram[MM(i->reg[0] + 2)]]) % 256;
  write(1, &c, 1);
  i->reg[0] = MM(i->reg[0] + 3);
  return (0);
}
