/*
** check_name.c for check_name in /home/marel_m/Rendu/Semestre_2/CPE/CPE_2015_corewar/asm
**
** Made by
** Login   <marel_m@epitech.net>
**
** Started on  Thu Mar 10 17:09:07 2016
** Last update Sun Mar 27 12:10:44 2016 marel_m
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include "asm.h"

int	check_double_quote_name(char *file)
{
  int	i;

  if (file[0] != '"')
    return (-1);
  i = 1;
  while (file[i] != '"')
    i++;
  if (i != (my_strlen(file) - 1) || i >= 129)
    return (-1);
  return (0);
}

void	stock_name(t_header *header, char *file)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (++i != (my_strlen(file) - 1))
    header->prog_name[j++] = file[i];
  header->prog_name[j] = '\0';
}

int	check_name(t_instruc *instruc, t_header *header, char *file)
{
  char	*new;

  if ((new = epure_file_name_com(file, 0)) == NULL)
    return (-1);
  if (my_strncmp(new, ".name", 5) != 0)
    return (write(2, "wrong .name\n", 12), -1);
  if ((new = epure_bt_file_name_com(instruc, new, 5)) == NULL)
    return (-1);
  if (check_double_quote_name(new) == -1)
    return (write(2, "wrong .name\n", 12), -1);
  stock_name(header, new);
  free(new);
  return (0);
}
