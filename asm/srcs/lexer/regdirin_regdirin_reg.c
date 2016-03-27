/*
** regdirin_regdirin_reg.c for regdirin_regdirin_reg in /home/marel_m/Rendu/Semestre_2/CPE/CPE_2015_corewar/asm
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Fri Mar 25 14:41:16 2016 marel_m
** Last update Fri Mar 25 15:21:54 2016 marel_m
*/

#include "asm.h"

int	check_first_rdi_rdi_r(t_instruc *instruc, t_list_instruc *elem,
			      char *file)
{
  instruc->reg_err = 0;
  if (check_registre_arg(instruc, elem, file, 1) == -1
       && check_direct_arg(instruc, elem, file, 1) == -1
       && check_indirect_arg(instruc, elem, file, 1) == -1)
    return (-1);
  return (0);
}

int	check_second_rdi_rdi_r(t_instruc *instruc, t_list_instruc *elem,
			       char *file)
{
  instruc->reg_err = 0;
  if (check_registre_arg(instruc, elem, file, 2) == -1
      && check_direct_arg(instruc, elem, file, 2) == -1
      && check_indirect_arg(instruc, elem, file, 2) == -1)
    return (-1);
  return (0);
}
