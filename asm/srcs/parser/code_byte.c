/*
** code_byte.c for byte in /home/bougon_p/rendu/CPE_2015_corewar/asm
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Wed Mar 16 20:14:07 2016 bougon_p
** Last update Fri Mar 25 17:49:03 2016 marel_m
*/

#include <unistd.h>
#include "asm.h"

char	check_arg1(t_info *info, int i)
{
  char	tmp;

  if (info->arg_1 != NULL)
    {
      if (info->arg_1[0] == '%')
	return (tmp = 0x80 >> (i * 8));
      else if (info->arg_1[0] == 'r')
	return (tmp = 0x40 >> (i * 8));
      else
	return (tmp = 0xC0 >> (i * 8));
    }
  return (0x00);
}

char	check_arg2(t_info *info, int i)
{
  char	tmp;

  if (info->arg_2 != NULL)
    {
      if (info->arg_2[0] == '%')
	return (tmp = 0x80 >> (i * 2));
      else if (info->arg_2[0] == 'r')
	return (tmp = 0x40 >> (i * 2));
      else
	return (tmp = 0xC0 >> (i * 2));
    }
  return (0x00);
}

char	check_arg3(t_info *info, int i)
{
  char	tmp;

  if (info->arg_3 != NULL)
    {
      if (info->arg_3[0] == '%')
	return (tmp = 0x80 >> (i * 2));
      else if (info->arg_3[0] == 'r')
	return (tmp = 0x40 >> (i * 2));
      else
	return (tmp = 0xC0 >> (i * 2));
    }
  return (0x00);
}

char	w_coding_byte(int fd, t_info *info)
{
  char	byte;
  int	i;

  byte = 0x00;
  i = -1;
  while (++i < 3)
    {
      if (i == 0)
	byte |= check_arg1(info, i);
      else if (i == 1)
	byte |= check_arg2(info, i);
      if (i == 2)
	byte |= check_arg3(info, i);
    }
  if (write(fd, &byte, sizeof(byte)) == -1)
    return (-1);
  return (byte);
}
