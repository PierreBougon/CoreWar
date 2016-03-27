/*
** fork.c for fork in /home/bougon_p/rendu/CPE_2015_corewar/asm
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Tue Mar 15 20:32:55 2016 bougon_p
** Last update Fri Mar 25 19:43:00 2016 bougon_p
*/

#include <unistd.h>
#include "asm.h"

int	w_fork(t_info *info, int fd, t_instruc *instruc)
{
  char	istr;

  istr = 0x0c;
  if (write(fd, &istr, sizeof(istr)) == -1)
    return (1);
  instruc->addr_wrt += 1;
  instruc->instr_addr = instruc->addr_wrt + instruc->addr_vir;
  if (check_short_lab(info, instruc, info->arg_1) == true)
    return (0);
  if (w_short(fd, info->arg_1, instruc) == 1)
    return (1);
  instruc->addr_wrt += 2;
  return (0);
}
