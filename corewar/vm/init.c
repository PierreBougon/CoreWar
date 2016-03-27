/*
** init.c for init in /home/duhieu_b/CPE/CPE_2015_corewar/corewar/vm
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Sat Mar 26 23:01:09 2016 benjamin duhieu
** Last update Sat Mar 26 23:01:36 2016 benjamin duhieu
*/

#include <stdlib.h>
#include "vm.h"

void	copy_registres(t_pc *src, t_pc *dst)
{
  int	i;

  i = 0;
  while (i < 16)
    {
      dst->reg[i] = src->reg[i];
      i += 1;
    }
}

int	add_pc(t_pc *pc, int pos, int cycle)
{
  t_pc	*tmp;
  t_pc	*elem;

  if (!(elem = malloc(sizeof(t_pc))))
    return (1);
  tmp = pc;
  while (tmp->next)
    tmp = tmp->next;
  copy_registres(tmp, elem);
  elem->champ = tmp->champ;
  elem->reg[0] = (pos < 0) ? MEM_SIZE + pos : pos % MEM_SIZE;
  elem->carry = tmp->carry;
  elem->cycle = cycle;
  elem->cycle = 0;
  elem->run = 0;
  elem->next = NULL;
  tmp->next = elem;
  return (0);
}

void		init_inst(t_data *data)
{
  data->inst[VM_ERROR] = &nothing;
  data->inst[VM_LIVE] = &live;
  data->inst[VM_LD] = &ld;
  data->inst[VM_ST] = &st;
  data->inst[VM_ADD] = &add;
  data->inst[VM_SUB] = &sub;
  data->inst[VM_AND] = &and;
  data->inst[VM_XOR] = &xor;
  data->inst[VM_OR] = &or;
  data->inst[VM_LDI] = &ldi;
  data->inst[VM_LLD] = &lld;
  data->inst[VM_LLDI] = &lldi;
  data->inst[VM_STI] = &sti;
  data->inst[VM_FORK] = &frk;
  data->inst[VM_LFORK] = &lfork;
  data->inst[VM_AFF] = &aff;
  data->inst[VM_ZJMP] = &zjump;
}
