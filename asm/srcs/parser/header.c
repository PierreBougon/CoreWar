/*
** header.c for HEADER in /home/bougon_p/rendu/CPE_2015_corewar/asm
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Tue Mar 15 18:20:22 2016 bougon_p
** Last update Sat Mar 26 20:43:27 2016 bougon_p
*/

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "asm.h"

int	write_magic(int fd)
{
  int	magic;

  magic = COREWAR_EXEC_MAGIC;
  magic = convert_littleend_to_bigend_int(magic);
  if (write(fd, &magic, sizeof(magic)) == -1)
    return (1);
  return (0);
}

int	write_name(t_header *head, int fd)
{
  int	size;
  int	i;

  i = -1;
  size = 129;
  write(fd, &head->prog_name[0], my_strlen(&head->prog_name[0]));
  size -= my_strlen(&head->prog_name[0]);
  while (++i < size + 3)
    write(fd, "\0", 1);
  return (0);
}

int	write_prog_size(UNUSED t_header *head, t_instruc *instruc, int fd)
{
  int		prog_size;
  int		addr;
  static bool	need_writtin = false;

  prog_size = 1;
  addr = 136;
  if (!need_writtin)
    write(fd, &prog_size, sizeof(prog_size));
  else
    {
      prog_size = instruc->addr_wrt + instruc->addr_vir;
      lseek(fd, addr, SEEK_SET);
      prog_size = convert_littleend_to_bigend_int(prog_size);
      write(fd, &prog_size, sizeof(prog_size));
    }
  need_writtin = true;
  return (0);
}

int	write_comment(t_header *head, int fd)
{
  int	size;
  int	i;

  size = 2049;
  i = -1;
  size -= my_strlen(&head->comment[0]);
  write(fd, &head->comment[0], my_strlen(&head->comment[0]));
  while (++i < size + 3)
    write(fd, "\0", 1);
  return (0);
}

int	write_header(int fd, t_header *head, t_instruc *instruc)
{
  if (write_magic(fd) == 1)
    return (1);
  if (write_name(head, fd) == 1)
    return (1);
  if (write_prog_size(head, instruc, fd) == 1)
    return (1);
  if (write_comment(head, fd) == 1)
    return (1);
  return (0);
}
