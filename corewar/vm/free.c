/*
** free.c for corewar in /brout_m/RENDU/CPE/CPE_2015_corewar/corewar
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Sat Mar 26 23:54:48 2016 marc brout
** Last update Sun Mar 27 00:43:05 2016 marc brout
*/

#include <stdlib.h>
#include <vm.h>

void	free_all_pc(t_pc *first)
{
  t_pc	*tmp;
  t_pc	*tmp2;

  tmp = first;
  while (tmp)
    {
      tmp2 = tmp->next;
      free(tmp);
      tmp = tmp2;
    }
}

void	free_data(t_data *data)
{
  free(data->ram);
  free_all_pc(data->champ[0]->pc);
  free_all_pc(data->champ[1]->pc);
  free_all_pc(data->champ[2]->pc);
  free_all_pc(data->champ[3]->pc);
  free(data->champ[0]);
  free(data->champ[1]);
  free(data->champ[2]);
  free(data->champ[3]);
}

void		free_args(t_pars *root)
{
  t_pars	*tmp;
  t_pars	*tmp2;

  tmp = root->next;
  while (tmp)
    {
      tmp2 = tmp->next;
      free(tmp->arg);
      free(tmp);
      tmp = tmp2;
    }
  free(root);
}
