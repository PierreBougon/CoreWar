/*
** str_null.c for NULL in /home/bougon_p/rendu/CPE_2015_corewar/asm
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Fri Mar 11 15:15:50 2016 bougon_p
** Last update Fri Mar 11 15:16:04 2016 bougon_p
*/

void	set_line_null(char *str, int size)
{
  int   i;

  i = -1;
  while (++i < size)
    str[i] = 0;
}
