/*
** lld.c for lld in /home/duhieu_b/CPE/CPE_2015_corewar/vm/parsing
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Mon Mar 21 22:58:34 2016 benjamin duhieu
** Last update Sat Mar 26 18:01:08 2016 benjamin duhieu
*/

#include "vm.h"
#include "my.h"

int	check_integrety_ld(unsigned first, char *ram, int i)
{
  if ((first == 2 && (ram[MM(i + 6)] < 1 || ram[MM(i + 6)] > 16)) ||
      (first == 3 && (ram[MM(i + 4)] < 1 || ram[MM(i + 4)] > 16)))
    return (1);
  return (0);
}

void	move_pc_ld(unsigned first, t_pc *i)
{
  if (first == 2)
    i->reg[0] = MM(i->reg[0] + 7);
  else
    i->reg[0] = MM(i->reg[0] + 5);
}

void		execute_ld_direct_no_idx(t_data *data, t_pc *i)
{
  int		dir;

  dir = RUIFM(data->ram, MM(i->reg[0] + 2));
  if (dir == 0)
    i->carry = 1;
  else
    i->carry = 0;
  i->reg[(int)data->ram[MM(i->reg[0] + 6)]] = dir;
}

void		execute_ld_indirect_no_idx(t_data *data, t_pc *i)
{
  int		indir;
  int		value;

  value = RSFM(data->ram, MM(i->reg[0] + 2));
  indir = RUIFM(data->ram, MM(i->reg[0] + value));
  if (indir == 0)
    i->carry = 1;
  else
    i->carry = 0;
  i->reg[(int)data->ram[MM(i->reg[0] + 4)]] = indir;
}

int		lld(t_data *data, t_pc *i)
{
  unsigned	first;
  unsigned	second;

  if (can_i_run(i, 10))
    return (0);
  first = (data->ram[MM(i->reg[0] + 1)] >> 6) & (char)3;
  second = (data->ram[MM(i->reg[0] + 1)] >> 4) & (char)3;
  if ((first != 2 && first != 3) || second != 1)
    return (0);
  else if (check_integrety_ld(first, data->ram, i->reg[0]))
    return (0);
  if (first == 2)
    execute_ld_direct_no_idx(data, i);
  else
    execute_ld_indirect_no_idx(data, i);
  move_pc_ld(first, i);
  return (0);
}
