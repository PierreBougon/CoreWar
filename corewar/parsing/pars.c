/*
** pars.c for pars in /CPE/CPE_2015_corewar/vm/parsing
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Mon Mar 21 12:58:17 2016 benjamin duhieu
** Last update Sun Mar 27 00:33:43 2016 marc brout
*/

#include <unistd.h>
#include "vm.h"
#include "my.h"

int		my_put_int_error(int nbr, int err)
{
  write(2, "prog number ", 12);
  my_putnbr_tofd(nbr, 2);
  write(2, " already used\n", 14);
  return (err);
}

int		pars_arg(char **av, t_pars *arg, t_data *data)
{
  int	i;
  int	chk;

  i = 1;
  while (av[i])
    {
      if ((chk = check_arg(av, &i, arg, data)) == 1)
	return (my_put_usage(av, 1));
      else if (chk == 2)
	{
	  if (av[i] == NULL)
	    my_put_error(MISS_COR, 1);
	  else if (load_champion(data->champ[data->i], av[i]))
	    return (2);
	  data->champ[data->i]->alive = 1;
	  data->champ[data->i]->valid = 1;
	  i += 1;
	  data->i += 1;
	}
    }
  recheck_prog_number(data);
  order_champ(data);
  return (0);
}

int		main(int argc, char **argv)
{
  t_pars	*arg;
  t_data	data;

  if (argc < 2 || !argv)
    return (my_put_usage(argv, 2));
  data.i = 0;
  data.dump = -1;
  g_endian = endianness();
  if (!(arg = init_list()) || init_ram(&data) ||
      init_champs(&data))
    return (1);
  if (pars_arg(argv, arg, &data) || place_all_champions(&data))
    return (1);
  if (count_players_alive(data.champ) == 1)
    {
      my_printf("Draw.\n");
      return (0);
    }
  if (launch_match(&data))
    return (1);
  free_data(&data);
  free_args(arg);
  return (0);
}
