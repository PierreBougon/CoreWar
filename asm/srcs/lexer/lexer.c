/*
** main.c for main in /home/marel_m/Rendu/Semestre_2/CPE/CPE_2015_corewar/asm/srcs/parser
**
** Made by
** Login   <marel_m@epitech.net>
**
** Started on  Thu Mar 10 15:41:48 2016
** Last update Sun Mar 27 12:15:08 2016 marel_m
*/

#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "asm.h"

int	check_file(t_header *header, t_instruc *instruc, int fd)
{
  char	*file;
  int	c;

  while (((file = get_next_line(fd)) != NULL && strlen(file) == 0)
	 || if_comment_text(file) == -1)
    {
      free(file);
      instruc->nb_l++;
    }
  if ((c = check_comment(header, instruc, file)) == -1
      || check_instructions(instruc, fd, c) == -1
      || check_if_label_exist(instruc) == -1)
    return (-1);
  free(file);
  return (0);
}

int	lexer(t_header *header, t_instruc *instruc, char *str)
{
  int	fd;
  char	*file;

  if ((fd = open(str, O_RDONLY)) == -1)
    return (file_wrong(str), -1);
  instruc->nb_l = 0;
  instruc->reg_err = 0;
  while (((file = get_next_line(fd)) != NULL && strlen(file) == 0)
	 || if_comment_text(file) == -1)
    {
      free(file);
      instruc->nb_l++;
    }
  instruc->nb_l++;
  if (check_name(instruc, header, file) == -1)
    return (-1);
  free(file);
  if (check_file(header, instruc, fd) == -1)
    return (-1);
  return (0);
}
