/*
** epure_file.c for epure_file in /home/marel_m/Rendu/Semestre_2/CPE/CPE_2015_corewar/asm
**
** Made by
** Login   <marel_m@epitech.net>
**
** Started on  Fri Mar 11 17:04:35 2016
** Last update Sun Mar 27 12:09:34 2016 marel_m
*/

#include "asm.h"

char	*epure_file_name_com(char *file, int i)
{
  int	j;
  char	*new;

  while (file && (file[i] == ' ' || file[i] == '\t'
		  || file[i] == ',') && file[i])
    i++;
  if ((new = malloc(sizeof(char) * (my_strlen(file) - i + 1))) == NULL)
    return (malloc_fail(), NULL);
  j = 0;
  while (file[i] != '\0')
    {
      new[j] = file[i];
      i++;
      j++;
    }
  new[j] = '\0';
  return (new);
}

char	*epure_bt_file_name_com(t_instruc *instruc, char *file, int i)
{
  int	j;
  char	*new;

  while (file && file[i] != '"' && file[i])
    {
      if (file[i] != ' ' && file[i] != '\t')
	return (synthax_error(instruc, 0), NULL);
      i++;
    }
  if ((new = malloc(sizeof(char) * (my_strlen(file) - i + 1))) == NULL)
    return (malloc_fail(), NULL);
  j = 0;
  while (file[i] != '\0')
    {
      new[j] = file[i];
      i++;
      j++;
    }
  new[j] = '\0';
  free(file);
  return (new);
}

char	*epure_file_instruc(char *file, int i)
{
  int	j;
  char	*new;

  while (file && (file[i] == ' ' || file[i] == '\t'
		  || file[i] == ',') && file[i])
    i++;
  if ((new = malloc(sizeof(char) * (my_strlen(file) - i + 1))) == NULL)
    return (malloc_fail(), NULL);
  j = 0;
  while (file[i] != '\0')
    {
      new[j] = file[i];
      i++;
      j++;
    }
  new[j] = '\0';
  return (new);
}

int	check_line(char *file)
{
  int	i;

  i = 0;
  while (file && (file[i] == ' ' || file[i] == '\t'
		  || file[i] == ',') && file[i])
    i++;
  if (i == my_strlen(file))
    return (-1);
  return (0);
}

int	check_end_instruc(char *file, int i)
{
  while (file && file[i] != '\0')
    {
      if (file[i] == '#' || file[i] == ';')
	return (0);
      else if (file[i] != ' ' && file[i] != '\t' && file[i] != ',')
	return (-1);
      i++;
    }
  return (0);
}
