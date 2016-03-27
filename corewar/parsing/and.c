/*
** and.c for and in /home/duhieu_b/CPE/CPE_2015_corewar/vm/parsing
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Mon Mar 21 22:54:20 2016 benjamin duhieu
** Last update Sat Mar 26 20:34:10 2016 marc brout
*/

#include "vm.h"

int	check_integrety(unsigned f, unsigned s, char *r, int i)
{
  if (((f == 3 && s == 3) && (r[M(i + 6)] < 1 || r[M(i + 6)] > 16)) ||
      ((f == 2 && s == 2) && (r[M(i + 10)] < 1 || r[M(i + 10)] > 16)) ||
      (((f == 3 && s == 2) || (f == 2 && s == 3)) &&
       (r[M(i + 8)] < 1 || r[M(i + 8)] > 16)) ||
      ((f == 1 && s == 2) && ((r[M(i + 2)] < 1 || r[M(i + 2)] > 16) ||
			      (r[M(i + 7)] < 1 || r[M(i + 7)] > 16))) ||
      ((f == 1 && s == 3) && ((r[M(i + 2)] < 1 || r[M(i + 2)] > 16) ||
			      (r[M(i + 5)] < 1 || r[M(i + 5)] > 16))) ||
      ((f == 2 && s == 1) && ((r[M(i + 6)] < 1 || r[M(i + 6)] > 16) ||
			      (r[M(i + 7)] < 1 || r[M(i + 7)] > 16))) ||
      ((f == 3 && s == 1) && ((r[M(i + 4)] < 1 || r[M(i + 4)] > 16) ||
			      (r[M(i + 5)] < 1 || r[M(i + 5)] > 16))) ||
      ((f == 1 && s == 1) && ((r[M(i + 2)] < 1 || r[M(i + 2)] > 16) ||
			      (r[M(i + 3)] < 1 || r[M(i + 3)] > 16) ||
			      (r[M(i + 4)] < 1 || r[M(i + 4)] > 16))))
    return (1);
  return (0);
}

int		recup_val(t_data *data,
			  t_pc *i,
			  t_inst *inst,
			  t_val *val)
{
  int		pos;

  pos = 2;
  if (inst->fi == 1 && (val->type[0] = 1))
    val->inte[0] = i->reg[(int)data->ram[M(i->reg[0] + pos)]], pos += 1;
  if (inst->fi == 3 && (val->type[0] = 1))
    val->inte[0] =
      RIFM(data->ram,
	   MM(i->reg[0] + IDX(RSFM(data->ram, M(i->reg[0] + pos))))),
      pos += 2;
  if (inst->fi == 2 && (val->type[0] = 1))
    val->inte[0] = RIFM(data->ram, M(i->reg[0] + pos)), pos += 4;
  if (inst->sd == 1 && (val->type[1] = 1))
    val->inte[1] = i->reg[(int)data->ram[M(i->reg[0] + pos)]], pos += 1;
  if (inst->sd == 3 && (val->type[1] = 1))
    val->inte[1] =
      RIFM(data->ram,
	   MM(i->reg[0] + IDX(RSFM(data->ram, M(i->reg[0] + pos))))),
      pos += 2;
  if (inst->sd == 2 && (val->type[1] = 1))
    val->inte[1] = RIFM(data->ram, M(i->reg[0] + pos)), pos += 4;
  val->inte[2] = (int)data->ram[MM(i->reg[0] + pos)], pos += 1;
  return (pos);
}

int		perform_and(t_pc *i,
			    t_val *val)
{
  if (val->type[0])
    {
      if (val->type[1])
	i->reg[val->inte[2]] = val->inte[0] & val->inte[1];
      else
	i->reg[val->inte[2]] = val->inte[0] & val->shrt[1];
    }
  else
    {
      if (val->type[1])
	i->reg[val->inte[2]] = val->shrt[0] & val->inte[1];
      else
	i->reg[val->inte[2]] = val->shrt[0] & val->shrt[1];
    }
  return (i->reg[val->inte[2]]);
}

int		and(t_data *data, t_pc *i)
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
  if (perform_and(i, &val))
    i->carry = 0;
  else
    i->carry = 1;
  i->reg[0] = MM(i->reg[0] + move);
  return (0);
}
