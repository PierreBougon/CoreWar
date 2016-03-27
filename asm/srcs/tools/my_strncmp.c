/*
** my_strncmp.c for my_strncmp in /home/marel_m/rendu/Piscine_C_J06/ex_07
**
** Made by maud marel
** Login   <marel_m@epitech.net>
**
** Started on  Mon Oct  5 23:33:30 2015 maud marel
** Last update Wed Mar 16 10:33:17 2016 
*/

int	my_strncmp(char *s1, char *s2, int n)
{
  int   i;
  int   tot;

  i = 0;
  n = n - 1;
  while (s1 && s2 &&
	 (s1[i] == s2[i]) && (s1[i] != 0) && (s2[i] != 0) && (i < n))
    i++;
  tot = s1[i] - s2[i];
  return (tot);
}
