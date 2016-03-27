/*
** error_stop.c for error_stop in /home/marel_m/Rendu/Semestre_2/CPE/CPE_2015_corewar/asm/srcs/error
**
** Made by
** Login   <marel_m@epitech.net>
**
** Started on  Fri Mar 11 14:10:16 2016 marel_m
** Last update Fri Mar 25 17:06:36 2016 marel_m
*/

#include <unistd.h>
#include "asm.h"

void	malloc_fail()
{
  write(2, "Can't perform malloc\n", 21);
}

void	file_wrong(char *str)
{
  write(2, "File ", 5);
  write(2, str, my_strlen(str));
  write(2, " not accessible\n", 16);
}

void	no_exist_label(t_list_label *label)
{
  write(2, "Label ", 6);
  write(2, label->name, my_strlen(label->name));
  write(2, " undefine line ", 15);
  my_put_nbr_error(label->pos);
  write(2, "\n", 1);
}

void	synthax_error(t_instruc *instruc, int nb)
{
  if (instruc->reg_err == 1 && nb == -1)
    write(2, "no such register line ", 22);
  else
    write(2, "Synthax error line ", 19);
  my_put_nbr_error(instruc->nb_l);
  write(2, "\n", 1);
  instruc->reg_err = 0;
}
