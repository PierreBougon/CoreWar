/*
** convert.c for CONVERT in /home/bougon_p/rendu/CPE_2015_corewar/asm
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Fri Mar 11 15:36:33 2016 bougon_p
** Last update Thu Mar 17 00:13:12 2016 bougon_p
*/

#include "asm.h"

int	convert_littleend_to_bigend_short(int var)
{
  int   tmp;

  tmp = 0;
  tmp = (var & 0xFF00) >> 8;
  tmp |= ((var & 0x00FF) << 8);
  return (tmp);
}

int	convert_littleend_to_bigend_int(int var)
{
  int   tmp;

  tmp = 0;
  tmp = (var & 0xFF000000) >> 24;
  tmp |= ((var & 0x00FF0000) >> 8);
  tmp |= (var & 0x0000FF00) << 8;
  tmp |= ((var & 0x000000FF) << 24);
  return (tmp);
}
