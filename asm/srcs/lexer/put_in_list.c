/*
** put_in_list.c for put_in_list in /home/marel_m/Rendu/Semestre_2/CPE/CPE_2015_corewar/asm
**
** Made by
** Login   <marel_m@epitech.net>
**
** Started on  Fri Mar 11 15:43:13 2016
** Last update Mon Mar 21 12:08:33 2016 Marel la plus belle <3
*/

#include "asm.h"

int		create_list(t_instruc *instruc)
{
  t_list_instruc	*new;

  if ((new = malloc(sizeof(t_list_instruc))) == NULL)
    return (malloc_fail(), -1);
  instruc->root = new;
  new->prev = new;
  new->next = new;
  instruc->lenght = 1;
  return (0);
}

t_list_instruc		*add_list_after(t_instruc *instruc)
{
  t_list_instruc	*new;

  if ((new = malloc(sizeof(t_list_instruc))) == NULL)
    return (NULL);
  if (instruc->root != NULL)
    {
      new->prev = instruc->root->prev;
      new->next = instruc->root;
      instruc->root->prev->next = new;
      instruc->root->prev = new;
    }
  instruc->lenght++;
  return (new);
}

int		create_list_label(t_instruc *instruc)
{
  t_list_label	*new;

  if ((new = malloc(sizeof(t_list_label))) == NULL)
    return (malloc_fail(), -1);
  instruc->lab = new;
  new->prev = new;
  new->next = new;
  instruc->lenght_label = 1;
  return (0);
}

t_list_label	*add_list_after_label(t_instruc *instruc)
{
  t_list_label	*new;

  if ((new = malloc(sizeof(t_list_label))) == NULL)
    return (malloc_fail(), NULL);
  if (instruc->lab != NULL)
    {
      new->prev = instruc->lab->prev;
      new->next = instruc->lab;
      instruc->lab->prev->next = new;
      instruc->lab->prev = new;
    }
  instruc->lenght_label++;
  return (new);
}
