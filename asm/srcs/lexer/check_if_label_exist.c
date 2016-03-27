/*
** check_if_label_exist.c for check_if_label_exist in /home/marel_m/Rendu/Semestre_2/CPE/CPE_2015_corewar/asm
**
** Made by
** Login   <marel_m@epitech.net>
**
** Started on  Tue Mar 15 19:47:32 2016
** Last update Sat Mar 26 18:02:04 2016 marel_m
*/

#include "asm.h"

char	*copy_lab(char *str)
{
  int	i;
  int	j;
  char	*new;

  if (str[0] == DIRECT_CHAR)
    i = 2;
  else
    i = 1;
  if ((new = malloc(sizeof(char) * (my_strlen(str)))) == NULL)
    return (malloc_fail(), NULL);
  j = 0;
  while (str[i] != ' ' && str[i] != '\t' && str[i] != ','
	 && str[i] != '\0')
    {
      new[j] = str[i];
      j++;
      i++;
    }
  new[j] = '\0';
  return (new);
}

int		check_in_list(t_instruc *instruc, char *lab)
{
  t_list_instruc	*tmp;
  int			i;
  char			*new;

  i = 0;
  tmp = instruc->root->next;
  if ((new = copy_lab(lab)) == NULL)
    return (-1);
  while (i < instruc->lenght - 1)
    {
      if (tmp->info->label != NULL &&
	  my_strncmp(tmp->info->label, new, my_strlen(new)) == 0)
	return (free(new), 0);
      tmp = tmp->next;
      i++;
    }
  return (-1);
}

int		check_if_label_exist(t_instruc *instruc)
{
  t_list_label	*tmp;
  int		i;

  i = 0;
  tmp = instruc->lab->next;
  while (i < instruc->lenght_label - 1)
    {
      if (check_in_list(instruc, tmp->name) == -1)
	return (no_exist_label(tmp), -1);
      tmp = tmp->next;
      i++;
    }
  return (0);
}
