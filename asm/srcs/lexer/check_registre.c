/*
** check_registre.c for check_registre in /home/marel_m/Rendu/Semestre_2/CPE/CPE_2015_corewar/asm/srcs
**
** Made by marel_m
** Login   <marel_m@epitech.net>
**
** Started on  Fri Mar 25 16:59:26 2016 marel_m
** Last update Sun Mar 27 01:39:22 2016 bougon_p
*/

#include "asm.h"

char	*copy_nb_registre(char *arg)
{
  char	*file;
  int	i;
  int	j;

  if ((file = malloc(sizeof(char) * my_strlen(arg))) == NULL)
    return (malloc_fail(), NULL);
  i = 1;
  j = 0;
  while (arg[i] != ' ' && arg[i] != ',' && arg[i] != '\t'
	 && arg[i] != '\0')
    file[j++] = arg[i++];
  file[j] = '\0';
  return (file);
}

int	check_registre_arg(t_instruc *instruc, t_list_instruc *elem,
			   char *file, int pos)
{
  int   i;
  int   nb;
  char  *arg;

  i = 0;
  while (file[i] != ' ' && file[i] != ',' && file[i] != '\t'
	 && file[i] != '\0')
    i++;
  if ((arg = my_strndup(file, i)) == NULL || arg[0] != 'r'
      || (file = copy_nb_registre(arg)) == NULL)
    return (free(arg), -1);
  nb = atoi(file);
  free(file);
  if (nb < 1 || nb > 16)
    {
      instruc->reg_err++;
      return (free(arg), -1);
    }
  stock_args(elem, arg, pos);
  return (0);
}
