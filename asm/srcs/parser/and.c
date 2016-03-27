/*
** and.c for and in /home/bougon_p/rendu/CPE_2015_corewar/asm
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Tue Mar 15 20:29:39 2016 bougon_p
** Last update Sat Mar 26 21:50:59 2016 bougon_p
*/

#include <unistd.h>
#include "asm.h"

int	and_arg_1(int fd, t_info *info, char byte, t_instruc *instruc)
{
  char  check;

  check = ((byte & 0xC0) >> 6);
  if (check == 0x02)
    {
      if (check_int_lab(info, instruc, info->arg_1) == true)
	return (0);
      w_int(fd, info->arg_1);
      instruc->addr_wrt += 4;
    }
  else if (check == 0x03)
    {
      if (check_short_lab(info, instruc, info->arg_1) == true)
	return (0);
      w_short(fd, info->arg_1, instruc);
      instruc->addr_wrt += 2;
    }
  else
    {
      w_reg(fd, info->arg_1);
      instruc->addr_wrt += 1;
    }
  return (0);
}

int	and_arg_2(int fd, t_info *info, char byte, t_instruc *instruc)
{
  char  check;

  check = ((byte & 0x30) >> 4);
  if (check == 0x02)
    {
      if (check_int_lab(info, instruc, info->arg_2) == true)
	return (0);
      w_int(fd, info->arg_2);
      instruc->addr_wrt += 4;
    }
  else if (check == 0x03)
    {
      if (check_short_lab(info, instruc, info->arg_1) == true)
	return (0);
      w_short(fd, info->arg_2, instruc);
      instruc->addr_wrt += 2;
    }
  else
    {
      w_reg(fd, info->arg_2);
      instruc->addr_wrt += 1;
    }
  return (0);
}

int	w_and(t_info *info, int fd, t_instruc *instruc)
{
  char	istr;
  char	byte;

  istr = 0x06;
  if (write(fd, &istr, sizeof(istr)) == -1)
    return (1);
  instruc->addr_wrt += 1;
  instruc->instr_addr = instruc->addr_wrt + instruc->addr_vir;
  if ((byte = w_coding_byte(fd, info)) == -1)
    return (1);
  instruc->addr_wrt += 1;
  if (and_arg_1(fd, info, byte, instruc) == 1 ||
      and_arg_2(fd, info, byte, instruc) == 1 ||
      w_reg(fd, info->arg_3) == 1)
    return (1);
  instruc->addr_wrt += 1;
  return (0);
}
