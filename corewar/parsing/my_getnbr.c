/*
** my_getnbr.c for my_getnbr.c in /home/brout_m/rendu/Piscine_C_J10
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Mon Oct 12 19:01:57 2015 marc brout
** Last update Mon Mar 21 14:13:30 2016 benjamin duhieu
*/

int		my_getnbr_prog(char *str)
{
  unsigned int	total;
  int		isneg;
  int		i;

  i = 0;
  isneg = 1;
  while ((str[i] == '-') || (str[i] == '+'))
    {
      if (str[i] == '-')
	return (0);
      i = i + 1;
    }
  total = 0;
  while ((str[i] >= '0') && (str[i] <= '9'))
    {
      if (((total * 10) + (str[i] - 48)) > 2147483647)
	return (0);
      total = ((total * 10) + (str[i] - 48));
      i = i + 1;
    }
  if (str[i])
    return (0);
  return (total * isneg);
}
