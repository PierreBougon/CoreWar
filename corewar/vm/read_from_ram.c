/*
** read_from_ram.c for corewar
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Wed Mar 23 08:36:28 2016 marc brout
** Last update Sun Mar 27 00:46:33 2016 marc brout
*/

#include <stdio.h>
#include "vm.h"
#include "my.h"

unsigned int	read_uint_from_ram(char *ram, int pos)
{
  t_core_int	nb;

  pos = (pos < 0) ? MEM_SIZE + pos : pos;
  if (g_endian)
    {
      nb.bytes[3] = ram[pos % MEM_SIZE];
      nb.bytes[2] = ram[(pos + 1) % MEM_SIZE];
      nb.bytes[1] = ram[(pos + 2) % MEM_SIZE];
      nb.bytes[0] = ram[(pos + 3) % MEM_SIZE];
    }
  else
    {
      nb.bytes[0] = ram[pos % MEM_SIZE];
      nb.bytes[1] = ram[(pos + 1) % MEM_SIZE];
      nb.bytes[2] = ram[(pos + 2) % MEM_SIZE];
      nb.bytes[3] = ram[(pos + 3) % MEM_SIZE];
    }
  return (nb.value);
}

int	read_int_from_ram(char *ram, int pos)
{
  t_core_int	nb;

  pos = (pos < 0) ? MEM_SIZE + pos : pos;
  if (g_endian)
    {
      nb.bytes[3] = ram[pos % MEM_SIZE];
      nb.bytes[2] = ram[(pos + 1) % MEM_SIZE];
      nb.bytes[1] = ram[(pos + 2) % MEM_SIZE];
      nb.bytes[0] = ram[(pos + 3) % MEM_SIZE];
    }
  else
    {
      nb.bytes[0] = ram[pos % MEM_SIZE];
      nb.bytes[1] = ram[(pos + 1) % MEM_SIZE];
      nb.bytes[2] = ram[(pos + 2) % MEM_SIZE];
      nb.bytes[3] = ram[(pos + 3) % MEM_SIZE];
    }
  return (nb.value);
}

short	read_short_from_ram(char* ram, int pos)
{
  t_core_short	nb;

  pos = (pos < 0) ? MEM_SIZE + pos : pos;
  if (g_endian)
    {
      nb.bytes[1] = ram[pos % MEM_SIZE];
      nb.bytes[0] = ram[(pos + 1) % MEM_SIZE];
    }
  else
    {
      nb.bytes[0] = ram[pos % MEM_SIZE];
      nb.bytes[1] = ram[(pos + 1) % MEM_SIZE];
    }
  return (nb.value);
}

void		write_int_to_ram(char *ram, unsigned int val, int pos)
{
  t_core_int	nb;

  nb.value = val;
  pos = (pos < 0) ? MEM_SIZE + pos : pos;
  if (g_endian)
    {
      ram[pos % MEM_SIZE] = nb.bytes[3];
      ram[(pos + 1) % MEM_SIZE] = nb.bytes[2];
      ram[(pos + 2) % MEM_SIZE] = nb.bytes[1];
      ram[(pos + 3) % MEM_SIZE] = nb.bytes[0];
    }
  else
    {
      ram[pos % MEM_SIZE] = nb.bytes[0];
      ram[(pos + 1) % MEM_SIZE] = nb.bytes[1];
      ram[(pos + 2) % MEM_SIZE] = nb.bytes[2];
      ram[(pos + 3) % MEM_SIZE] = nb.bytes[3];
    }
}

void		write_short_to_ram(char *ram, unsigned short val,
				   int pos)
{
  t_core_short	nb;

  nb.value = val;
  pos = (pos < 0) ? MEM_SIZE + pos : pos;
  if (g_endian)
    {
      ram[(pos + 2) % MEM_SIZE] = nb.bytes[1];
      ram[(pos + 3) % MEM_SIZE] = nb.bytes[0];
    }
  else
    {
      ram[pos % MEM_SIZE] = nb.bytes[0];
      ram[(pos + 1) % MEM_SIZE] = nb.bytes[1];
    }
}
