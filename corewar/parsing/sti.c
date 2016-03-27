/*
** sti.c for sti in /home/duhieu_b/CPE/CPE_2015_corewar/vm/parsing
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Mon Mar 21 22:57:35 2016 benjamin duhieu
** Last update Sun Mar 27 00:48:52 2016 marc brout
*/

#include "my.h"
#include "vm.h"

int	check_integrety_sti(unsigned sc, unsigned th, char *ram, int i)
{
  if (((sc == 1 && th == 1) &&
       ((ram[MM(i + 2)] < 1 || ram[MM(i + 2)] > 16) ||
	(ram[MM(i + 3)] < 1 || ram[MM(i + 3)] > 16) ||
	(ram[MM(i + 4)] < 1 || ram[MM(i + 4)] > 16))) ||
      ((sc == 1 && th == 2) &&
       ((ram[MM(i + 2)] < 1 || ram[MM(i + 2)] > 16) ||
	(ram[MM(i + 3)] < 1 || ram[MM(i + 3)] > 16))) ||
      (((sc == 2 || sc == 3) && th == 1) && ((ram[MM(i + 2)] < 1 ||
					      ram[MM(i + 2)] > 16) ||
					     (ram[MM(i + 5)] < 1 ||
					      ram[MM(i + 5)] > 16))) ||
      ((sc != 1 && th != 1) &&
       ((ram[MM(i + 2)] < 1 || ram[MM(i + 2)] > 16))))
    return (1);
  return (0);
}

void	move_pc_sti(unsigned second, unsigned third, t_pc *i)
{
  if (((second == 2 || second == 3) && third == 1) ||
      (second == 1 && third == 2))
    i->reg[0] = MM(i->reg[0] + 6);
  else if (((second == 2 || second == 3) && third == 2))
    i->reg[0] = MM(i->reg[0] + 7);
  else
    i->reg[0] = MM(i->reg[0] + 5);
}

void		execut_sti(t_data *d, t_inst *arg, t_pc *pc)
{
  int		val;
  int		val2;
  int		val3;
  int		pos;

  pos = 2;
  val = pc->reg[(int)d->ram[MM(pc->reg[0] + pos)]], pos += 1;
  if (arg->sd == 1)
    val2 = pc->reg[(int)d->ram[MM(pc->reg[0] + pos)]], pos += 1;
  if (arg->sd == 2)
    val2 = RSFM(d->ram, MM(pc->reg[0] + pos)), pos += 2;
  if (arg->sd == 3)
    val2 = RIFM
      (d->ram, MM(pc->reg[0] +
		  IDX(RSFM(d->ram, MM(pc->reg[0] + pos))))),
      pos += 2;
  if (arg->th == 1)
    val3 = pc->reg[(int)d->ram[MM(pc->reg[0] + pos)]];
  if (arg->th == 2)
    val3 = RSFM(d->ram, MM(pc->reg[0] + pos));
  write_int_to_ram(d->ram, val, MM(pc->reg[0] + val2 + val3));
}

int		sti(t_data *data, t_pc *i)
{
  t_inst	arg;

  if (can_i_run(i, 25))
    return (0);
  arg.fi = (data->ram[MM(i->reg[0] + 1)] >> 6) & (char)3;
  arg.sd = (data->ram[MM(i->reg[0] + 1)] >> 4) & (char)3;
  arg.th = (data->ram[MM(i->reg[0] + 1)] >> 2) & (char)3;
  if (arg.fi != 1 || (arg.sd != 1 && arg.sd != 2 && arg.sd != 3) ||
      (arg.th != 1 && arg.th != 2))
    return (0);
  if (check_integrety_sti(arg.sd, arg.th, data->ram, i->reg[0]))
    return (0);
  execut_sti(data, &arg, i);
  move_pc_sti(arg.sd, arg.th, i);
  return (0);
}
