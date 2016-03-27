/*
** check_char.c for check_char in /home/marel_m/Rendu/Semestre_2/CPE/CPE_2015_corewar/asm
**
** Made by
** Login   <marel_m@epitech.net>
**
** Started on  Fri Mar 11 18:10:55 2016
** Last update Fri Mar 11 18:20:23 2016 
*/

#include "asm.h"

int	check_char(char c)
{
  int	i;

  i = 0;
  while (i < 37)
    {
      if (LABEL_CHARS[i] == c)
	return (0);
      i++;
    }
  return (-1);
}
