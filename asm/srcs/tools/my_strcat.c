/*
** my_strcat.c for strcat in /home/bougon_p/rendu/CPE_2015_corewar/asm
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Mon Mar 14 19:02:45 2016 bougon_p
** Last update Fri Mar 25 17:29:41 2016 marel_m
*/

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	p;

  i = -1;
  p = -1;
  while (dest[++i] != 0);
  while (src[++p] != 0)
    dest[i++] = src[p];
  dest[i] = 0;
  return (dest);
}
