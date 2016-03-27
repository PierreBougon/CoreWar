/*
** initlist.c for LIST in /home/bougon_p/rendu/CPE_2015_corewar/asm
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Wed Mar 23 22:24:42 2016 bougon_p
** Last update Sat Mar 26 21:45:15 2016 bougon_p
*/

#include "asm.h"

int		create_labcdlist(t_cdlist **root)
{
  t_cdlist	*elem;

  if ((elem = malloc(sizeof(t_cdlist))) == NULL)
      return (1);
  *root = elem;
  elem->prev = *root;
  elem->next = *root;
  return (0);
}

int		add_last_labcdl(t_cdlist *root, void *_data)
{
  t_cdlist	*elem;

  if ((elem = malloc(sizeof(t_cdlist))) == NULL)
      return (1);
  if (root != NULL)
    {
      elem->prev = root->prev;
      elem->next = root;
      root->prev->next = elem;
      root->prev = elem;
    }
  elem->data = _data;
  return (0);
}

int		free_lablist(t_arglist *arg)
{
  t_cdlist	*tmp;
  t_cdlist	*tmp2;

  tmp = arg->root->next;
  while (tmp != arg->root)
    {
      tmp2 = tmp->next;
      if (tmp->data->name != NULL)
	free(tmp->data->name);
      free(tmp->data);
      free(tmp);
      tmp = tmp2;
    }
  free(tmp);
  return (0);
}
