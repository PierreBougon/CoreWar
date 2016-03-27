/*
** reg_regdirin_regdir.c for reg_regdirin_regdir in /home/marel_m/Rendu/Semestre_2/CPE/CPE_2015_corewar/asm
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Fri Mar 25 14:56:37 2016 marel_m
** Last update Fri Mar 25 15:30:22 2016 marel_m
*/

#include "asm.h"

int	check_second_r_rdi_rd(t_instruc *instruc, t_list_instruc *elem,
			     char *file)
{
  instruc->reg_err = 0;
  if (check_registre_arg(instruc, elem, file, 2) == -1
      && check_direct_arg(instruc, elem, file, 2) == -1
      && check_indirect_arg(instruc, elem, file, 2) == -1)
    return (-1);
  return (0);
}

int	check_third_r_rdi_rd(t_instruc *instruc, t_list_instruc *elem,
			     char *file)
{
  instruc->reg_err = 0;
  if (check_registre_arg(instruc, elem, file, 3) == -1
      && check_direct_arg(instruc, elem, file, 3) == -1)
    return (-1);
  return (0);
}
