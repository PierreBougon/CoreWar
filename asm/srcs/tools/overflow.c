/*
** overflow.c for OVERFLOW in /home/bougon_p/rendu/CPE_2015_corewar
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Sat Mar 26 15:37:47 2016 bougon_p
** Last update Sat Mar 26 15:39:53 2016 bougon_p
*/

int		my_overflow(char *str)
{
  unsigned int	total;
  int		isneg;
  int		i;

  i = 0;
  isneg = 1;
  while ((str[i] == '-') || (str[i] == '+'))
    {
      if (str[i] == '-')
	isneg = -isneg;
      i = i + 1;
    }
  total = 0;
  while ((str[i] >= '0') && (str[i] <= '9'))
    {
      if (((total * 10) + (str[i] - 48)) > 2147483647)
	return (1);
      total = ((total * 10) + (str[i] - 48));
      i = i + 1;
    }
  return (0);
}
