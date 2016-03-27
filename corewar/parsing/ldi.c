/*
** ldi.c for ldi in /home/duhieu_b/CPE/CPE_2015_corewar/vm/parsing
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Mon Mar 21 22:57:05 2016 benjamin duhieu
** Last update Sun Mar 27 00:48:33 2016 marc brout
*/

#include "vm.h"

int		recup_val_ldi(t_data *data,
			      t_pc *i,
			      t_inst *inst,
			      t_val *val)
{
  int		pos;

  pos = 2;
  if (inst->fi == 1)
    val->inte[0] = i->reg[(int)data->ram[M(i->reg[0] + pos)]], pos += 1,
      val->type[0] = 1;
  if (inst->fi == 2)
    val->shrt[0] = RSFM(data->ram, M(i->reg[0] + pos)), pos += 2,
      val->type[0] = 0;
  if (inst->fi == 3)
    val->shrt[0] = RSFM(data->ram, M(i->reg[0] + pos)), pos += 2,
      val->type[0] = 0;
  if (inst->sd == 1)
    val->inte[1] = i->reg[(int)data->ram[M(i->reg[0] + pos)]], pos += 1,
      val->type[1] = 1;
  if (inst->sd == 2)
    val->shrt[1] = RSFM(data->ram, M(i->reg[0] + pos)), pos += 2,
      val->type[1] = 0;
  if (inst->sd == 3)
    val->shrt[1] = RSFM(data->ram, M(i->reg[0] + pos)), pos += 2,
      val->type[1] = 0;
  val->inte[2] = (int)data->ram[MM(i->reg[0] + pos)], pos += 1;
  return (pos);
}

int		perform_ldi(t_data *data, t_val *val, t_pc *i)
{
  if (val->type[0])
    {
      if (val->type[1])
	i->reg[val->inte[2]] =
	  RIFM(data->ram, MM(i->reg[0] + IDX(IDX(val->inte[0])) +
			     val->inte[1]));
      else
	i->reg[val->inte[2]] =
	  RIFM(data->ram, MM(i->reg[0] + IDX(IDX(val->inte[0])) +
			     val->shrt[1]));
    }
  else
    {
      if (val->type[1])
	i->reg[val->inte[2]] =
	  RIFM(data->ram, MM(i->reg[0] + IDX(IDX(val->shrt[0])) +
			     val->inte[1]));
      else
	i->reg[val->inte[2]] =
	  RIFM(data->ram, MM(i->reg[0] + IDX(IDX(val->shrt[0])) +
			     val->shrt[1]));
    }
  return (i->reg[val->inte[2]]);
}

int		ldi(t_data *data, t_pc *i)
{
  t_inst	inst;
  t_val		val;
  int		move;

  if (can_i_run(i, 25))
    return (0);
  inst.fi = (data->ram[MM(i->reg[0] + 1)] >> 6) & (char)3;
  inst.sd = (data->ram[MM(i->reg[0] + 1)] >> 4) & (char)3;
  inst.th = (data->ram[MM(i->reg[0] + 1)] >> 2) & (char)3;
  if ((inst.fi != 1 && inst.fi != 2 && inst.fi != 3) ||
      (inst.sd != 1 && inst.sd != 2) || inst.th != 1)
    return (0);
  if (check_integrety_ldi(inst.fi, inst.sd, data->ram, i->reg[0]))
    return (0);
  move = recup_val_ldi(data, i, &inst, &val);
  if (perform_ldi(data, &val, i))
    i->carry = 0;
  else
    i->carry = 1;
  i->reg[0] = MM(i->reg[0] + move);
  return (0);
}
