/*
** ld.c for LD in /home/bougon_p/rendu/CPE_2015_corewar/asm
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Tue Mar 15 20:26:16 2016 bougon_p
** Last update Sun Mar 27 01:38:55 2016 bougon_p
*/

#include <unistd.h>
#include "asm.h"

int	ld_arg_1(int fd, t_info *info, char byte, t_instruc *instruc)
{
  char  check;

  check = ((byte & 0xC0) >> 6);
  if (check == 0x02)
    {
      if (check_int_lab(info, instruc, info->arg_1) == true)
	return (0);
      if (w_int(fd, info->arg_1) == 1)
	return (1);
      instruc->addr_wrt += 4;
    }
  else if (check == 0x03)
    {
      if (check_short_lab(info, instruc, info->arg_1) == true)
	return (0);
      if (w_short(fd, info->arg_1, instruc) == 1)
        return (1);
      instruc->addr_wrt += 2;
    }
  return (0);
}

int	w_ld(t_info *info, int fd, t_instruc *instruc)
{
  char	istr;
  char	byte;

  istr = 0x02;
  if (write(fd, &istr, sizeof(istr)) == -1)
    return (1);
  instruc->addr_wrt += 1;
  instruc->instr_addr = instruc->addr_wrt + instruc->addr_vir;
  if ((byte = w_coding_byte(fd, info)) == -1)
    return (1);
  instruc->addr_wrt += 1;
  if (ld_arg_1(fd, info, byte, instruc) == 1)
    return (1);
  if (w_reg(fd, info->arg_2) == 1)
    return (1);
  instruc->addr_wrt += 1;
  return (0);
}
