/*
** w_args.c for ARGS in /home/bougon_p/rendu/CPE_2015_corewar/asm
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Thu Mar 17 15:33:53 2016 bougon_p
** Last update Fri Mar 25 19:40:06 2016 bougon_p
*/

#include <unistd.h>
#include "asm.h"

int	w_reg(int fd, char *arg)
{
  char	reg;

  reg = my_getnbr(&arg[1]);
  if (write(fd, &reg, sizeof(reg)) == -1)
    return (1);
  return (0);
}

int	w_int(int fd, char *arg)
{
  int	arg_nb;

  arg_nb = my_getnbr(&arg[1]);
  arg_nb = convert_littleend_to_bigend_int(arg_nb);
  if (write(fd, &arg_nb, sizeof(arg_nb)) == -1)
    return (1);
  return (0);
}

int	w_short(int fd, char *arg, t_instruc *instruc)
{
  short	arg_nb;

  if (arg[0] == '%')
    arg_nb = my_getnbr(&arg[1]);
  else
      {
	arg_nb = my_getnbr(arg);
	if (arg_nb > IDX_MOD)
	  direct_too_big("Warning Indirection to far line ",
			instruc->nb_l);
    }
  arg_nb = convert_littleend_to_bigend_short(arg_nb);
  if (write(fd, &arg_nb, sizeof(arg_nb)) == -1)
    return (1);
  return (0);
}

int	w_label(int fd, t_cdlist *to_find, t_cdlist *real)
{
  int	addr_int;
  short	addr_short;

  if (to_find->data->nb_bytes == 4)
    {
      addr_int = real->data->addr - to_find->data->addr + 1;
      addr_int = convert_littleend_to_bigend_int(addr_int);
      if (write(fd, &addr_int, sizeof(addr_int)) == -1)
	return (1);
    }
  else if (to_find->data->nb_bytes == 2)
    {
      addr_short = (short)real->data->addr - to_find->data->addr + 1;
      addr_short = convert_littleend_to_bigend_short(addr_short);
      if (write(fd, &addr_short, sizeof(addr_short)) == -1)
	return (1);
    }
  return (0);
}
