/*
** error.c for ERROR in /home/bougon_p/rendu/CPE_2015_corewar/asm
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Fri Mar 25 16:55:31 2016 bougon_p
** Last update Fri Mar 25 19:46:10 2016 bougon_p
*/

#include <unistd.h>
#include "asm.h"

void	direct_too_big(char *str, int line)
{
  write(2, str, my_strlen(str));
  my_put_nbr_error(line);
  write(2, "\n", 1);
}
