/*
** dump.c for corewar
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Tue Mar 22 10:46:07 2016 marc brout
** Last update Wed Mar 23 12:16:14 2016 marc brout
*/

#include <unistd.h>
#include "vm.h"
#include "my.h"

void		octect_to_base(char octect, char hexa[2],
			       char *base)
{
  unsigned	a;
  unsigned	b;

  a = 0;
  b = 0;
  a = a | ((octect & 0xF0) >> 4);
  b = b | ((octect & 0x0F));
  a = a % my_strlen(base);
  b = b % my_strlen(base);
  if (g_endian)
    {
      hexa[0] = base[(int)a];
      hexa[1] = base[(int)b];
    }
  else
    {
      hexa[1] = base[(int)a];
      hexa[0] = base[(int)b];
    }
}

void		dump(char *ram)
{
  char		hexa[2];
  int		i;

  i = 0;
  while (i < MEM_SIZE)
    {
      if (i % 32 && i != 0)
	write(1, " ", 1);
      octect_to_base(ram[i], hexa, "0123456789ABCDEF");
      write(1, hexa, 2);
      i += 1;
      if (!(i % 32))
      	write(1, "\n", 1);
    }
  write(1, "\n", 1);
}
