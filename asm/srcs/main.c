/*
** main.c for main
**
** Made by
** Login   <marel_m@epitech.net>
**
** Started on  Fri Mar 11 13:57:07 2016
** Last update Sat Mar 26 19:07:42 2016 bougon_p
*/

#include <unistd.h>
#include "asm.h"

int		main(int ac, char **av)
{
  t_header	header;
  t_instruc	instruc;
  int		i;

  if (ac == 1)
    {
      write(2, "Wrong arguments\n", 16);
      return (-1);
    }
  i = 0;
  while (++i < ac)
    {
      if (lexer(&header, &instruc, av[i]) == -1)
	return (-1);
      parser(av[i], &header, &instruc);
      free_list(&instruc);
    }
  return (0);
}
