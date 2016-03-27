/*
** free_tab.c for FREETAB$ in /home/bougon_p/rendu/CPE_2015_corewar/asm
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Mon Mar 21 19:30:59 2016 bougon_p
** Last update Mon Mar 21 20:54:58 2016 bougon_p
*/

#include "asm.h"

void	free_tab(char **tab)
{
  int	i;

  i = -1;
  while (tab[++i] != NULL)
    free(tab[i]);
  free(tab);
}
