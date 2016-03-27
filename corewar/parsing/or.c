/*
** or.c for or in /home/duhieu_b/CPE/CPE_2015_corewar/vm/parsing
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Mon Mar 21 22:55:18 2016 benjamin duhieu
** Last update Sat Mar 26 18:01:29 2016 benjamin duhieu
*/

#include "vm.h"

int		perform_or(t_pc *i,
			   t_val *val)
{
  if (val->type[0])
    {
      if (val->type[1])
	i->reg[val->inte[2]] = val->inte[0] | val->inte[1];
      else
	i->reg[val->inte[2]] = val->inte[0] | val->shrt[1];
    }
  else
    {
      if (val->type[1])
	i->reg[val->inte[2]] = val->shrt[0] | val->inte[1];
      else
	i->reg[val->inte[2]] = val->shrt[0] | val->shrt[1];
    }
  return (i->reg[val->inte[2]]);
}

int		or(t_data *data, t_pc *i)
{
  t_inst	inst;
  t_val		val;
  int		move;

  if (can_i_run(i, 6))
    return (0);
  inst.fi = (data->ram[MM(i->reg[0] + 1)] >> 6) & (char)3;
  inst.sd = (data->ram[MM(i->reg[0] + 1)] >> 4) & (char)3;
  inst.th = (data->ram[MM(i->reg[0] + 1)] >> 2) & (char)3;
  if ((inst.fi != 1 && inst.fi != 2 && inst.fi != 3) ||
      (inst.sd != 1 && inst.sd != 2 && inst.sd != 3) || inst.th != 1)
    return (0);
  if (check_integrety(inst.fi, inst.sd, data->ram, i->reg[0]))
    return (0);
  move = recup_val(data, i, &inst, &val);
  if (perform_or(i, &val))
    i->carry = 0;
  else
    i->carry = 1;
  i->reg[0] = MM(i->reg[0] + move);
  return (0);
}
