/*
** check_good_args.c for check_good_args.c in /home/marel_m/Rendu/Semestre_2/CPE/CPE_2015_corewar/asm
**
** Made by
** Login   <marel_m@epitech.net>
**
** Started on  Sun Mar 13 15:47:40 2016
** Last update Sat Mar 26 20:39:31 2016 marel_m
*/

#include <unistd.h>
#include "asm.h"

int		check_if_label(t_instruc *instruc, char *file, int i)
{
  t_list_label	*new;

  if (file[i] != LABEL_CHAR)
    return (-1);
  i++;
  while (file[i] != ' ' && file[i] != '\t' && file[i] != ','
	 && file[i] != '\0')
    {
      if (check_char(file[i]) == -1)
	return (-1);
      i++;
    }
  if ((new = add_list_after_label(instruc)) == NULL)
    return (-1);
  new->name = my_strndup(file, i);
  new->pos = instruc->nb_l;
  return (0);
}

int	check_if_val(t_instruc *instruc, char *file, int i, int d)
{
  if (file[i] < '0' && file[i] > '9' && file[i] != '-')
    return (-1);
  i++;
  while (file[i] != ' ' && file[i] != '\t' && file[i] != ','
	 && file[i] != '\0')
    {
      if (file[i] < '0' || file[i] > '9')
	return (-1);
      i++;
    }
  if (d == 1 && my_overflow(&file[1]) == 1)
    {
      write(2, "Warning Direct too big line ", 28);
      my_put_nbr_error(instruc->nb_l);
      write(2, "\n", 1);
    }
  return (0);
}

int	check_direct_arg(t_instruc *instruc, t_list_instruc *elem,
			 char *file, int pos)
{
  int	i;
  char	*arg;

  i = 0;
  while (file[i] != ' ' && file[i] != ',' && file[i] != '\t'
	 && file[i] != '\0')
    i++;
  if ((arg = my_strndup(file, i)) == NULL
      || arg[0] != DIRECT_CHAR
      || (check_if_label(instruc, arg, 1) == -1
	  && check_if_val(instruc, arg, 1, 1) == -1))
    return (free(arg), -1);
  stock_args(elem, arg, pos);
  return (0);
}

int	check_indirect_arg(t_instruc *instruc, t_list_instruc *elem,
			   char *file, int pos)
{
  int	i;
  char	*arg;

  i = 0;
  while (file[i] != ' ' && file[i] != ',' && file[i] != '\t'
	 && file[i] != '\0')
    i++;
  if ((arg = my_strndup(file, i)) == NULL
      || (check_if_label(instruc, arg, 0) == -1
	  && check_if_val(instruc, arg, 0, 0) == -1))
    return (free(arg), -1);
  stock_args(elem, arg, pos);
  return (0);
}
