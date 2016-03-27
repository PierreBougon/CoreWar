/*
** list_arg.c for list_arg in /home/duhieu_b/CPE/CPE_2015_corewar/vm/parsing
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Mon Mar 21 13:28:23 2016 benjamin duhieu
** Last update Tue Mar 22 00:51:38 2016 marc brout
*/

#include <stdlib.h>
#include "vm.h"
#include "my.h"

int		add_dump_in_list(t_pars *root)
{
  t_pars	*new_elem;

  if (!(new_elem = malloc(sizeof(t_pars))))
    return (1);
  new_elem->next = root->next;
  new_elem->arg = my_strdup("-dump");
  new_elem->chk_arg = &chk_dump;
  root->next = new_elem;
  return (0);
}

int		add_prog_nbr_in_list(t_pars *root)
{
  t_pars	*new_elem;

  if (!(new_elem = malloc(sizeof(t_pars))))
    return (1);
  new_elem->next = root->next;
  new_elem->arg = my_strdup("-n");
  new_elem->chk_arg = &chk_prog_nbr;
  root->next = new_elem;
  return (0);
}

int		add_adress_in_list(t_pars *root)
{
  t_pars	*new_elem;

  if (!(new_elem = malloc(sizeof(t_pars))))
    return (1);
  new_elem->next = root->next;
  new_elem->arg = my_strdup("-a");
  new_elem->chk_arg = &chk_adress;
  root->next = new_elem;
  return (0);
}

t_pars		*init_list()
{
  t_pars	*root;

  if (!(root = malloc(sizeof(t_pars))))
    return (NULL);
  root->next = NULL;
  if (add_dump_in_list(root))
    return (NULL);
  if (add_prog_nbr_in_list(root))
    return (NULL);
  if (add_adress_in_list(root))
    return (NULL);
  return (root);
}
