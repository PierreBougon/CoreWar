/*
** code.c for CODE in /home/bougon_p/rendu/CPE_2015_corewar/asm
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Tue Mar 15 18:23:04 2016 bougon_p
** Last update Fri Mar 25 19:43:01 2016 bougon_p
*/

#include "asm.h"

int	check_instruct(char *name, char **tabname)
{
  int	i;

  i = 0;
  while (my_strcmp(name, tabname[i]) != 0)
    {
      i++;
      if (i > NB_INSTRUCTIONS)
	return (-1);
    }
  return (i);
}

int	stock_real_lab(t_instruc *instruc, t_info *info)
{
  t_lablist     *lab;

  if ((lab = malloc(sizeof(t_lablist))) == NULL)
    return (1);
  lab->addr = instruc->addr_vir + instruc->addr_wrt;
  lab->name = my_strduplab(info->label);
  lab->nb_bytes = 0;
  add_last_labcdl(instruc->real_lab.root, lab);
  return (0);
}

int		write_code(int fd, t_instruc *instruc,
			   t_tabinstr *tabinstr, char **instr)
{
  t_list_instruc	*act_instr;
  int			index;
  int			i;

  i = 0;
  act_instr = instruc->root->next;
  while (act_instr != instruc->root)
    {
      i++;
      instruc->nb_l = i;
      if ((index = check_instruct(act_instr->info->name, instr)) == -1)
	return (1);
      if (act_instr->info->label)
	stock_real_lab(instruc, act_instr->info);
      if (tabinstr->tabinstr[index](act_instr->info, fd, instruc))
	return (1);
      act_instr = act_instr->next;
    }
  return (0);
}
