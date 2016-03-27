/*
** my_strncpy.c for my_strncpy in /home/marel_m/rendu/Piscine_C_J06/ex_03
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Mon Oct  5 11:17:08 2015 maud marel
** Last update Sat Mar 26 21:37:57 2016 bougon_p
*/

#include <stdlib.h>
#include "asm.h"

char	*my_strndup(char *src, int n)
{
  int	i;
  char	*dest;

  if (my_strlen(src) + n - 1 <= 0)
    return (NULL);
  if ((dest = malloc(sizeof(char) * (my_strlen(src) + n))) == NULL)
    return (malloc_fail(), NULL);
  i = 0;
  while (src && i < n && src[i] != '\0')
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}

char	*my_strduplab(char *src)
{
  int	i;
  char	*dest;

  if (my_strlen(src) - 1 < 0)
    return (NULL);
  if ((dest = malloc(sizeof(char) * (my_strlen(src) + 1))) == NULL)
    return (malloc_fail(), NULL);
  i = -1;
  while (src[++i] != '\0'
	 && (src[i] != ':' && src[i] != ' '))
    dest[i] = src[i];
  dest[i] = '\0';
  return (dest);
}
