/*
** parser.c for PARSE in /home/bougon_p/rendu/CPE_2015_corewar/asm
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Thu Mar 10 15:08:25 2016 bougon_p
** Last update Sat Mar 26 16:29:42 2016 bougon_p
*/

#include <unistd.h>
#include "asm.h"

int	init_tabinstr(t_tabinstr *tabinstr)
{
  if ((tabinstr->tabinstr = malloc
       (sizeof(t_tabinstr) * NB_INSTRUCTIONS)) == NULL)
    return (1);
  tabinstr->tabinstr[0] = &w_live;
  tabinstr->tabinstr[1] = &w_ld;
  tabinstr->tabinstr[2] = &w_st;
  tabinstr->tabinstr[3] = &w_add;
  tabinstr->tabinstr[4] = &w_sub;
  tabinstr->tabinstr[5] = &w_and;
  tabinstr->tabinstr[6] = &w_or;
  tabinstr->tabinstr[7] = &w_xor;
  tabinstr->tabinstr[8] = &w_zjmp;
  tabinstr->tabinstr[9] = &w_ldi;
  tabinstr->tabinstr[10] = &w_sti;
  tabinstr->tabinstr[11] = &w_fork;
  tabinstr->tabinstr[12] = &w_lld;
  tabinstr->tabinstr[13] = &w_lldi;
  tabinstr->tabinstr[14] = &w_lfork;
  tabinstr->tabinstr[15] = &w_aff;
  return (0);
}

char	**init_instr()
{
  char	**tab;

  if ((tab = malloc(sizeof(char *) * (NB_INSTRUCTIONS + 1))) == NULL)
    return (NULL);
  if ((tab[0] = my_strdup("live")) == NULL ||
      (tab[1] = my_strdup("ld")) == NULL ||
      (tab[2] = my_strdup("st")) == NULL ||
      (tab[3] = my_strdup("add")) == NULL ||
      (tab[4] = my_strdup("sub")) == NULL ||
      (tab[5] = my_strdup("and")) == NULL ||
      (tab[6] = my_strdup("or")) == NULL ||
      (tab[7] = my_strdup("xor")) == NULL ||
      (tab[8] = my_strdup("zjmp")) == NULL ||
      (tab[9] = my_strdup("ldi")) == NULL ||
      (tab[10] = my_strdup("sti")) == NULL ||
      (tab[11] = my_strdup("fork")) == NULL ||
      (tab[12] = my_strdup("lld")) == NULL ||
      (tab[13] = my_strdup("lldi")) == NULL ||
      (tab[14] = my_strdup("lfork")) == NULL ||
      (tab[15] = my_strdup("aff")) == NULL)
    return (NULL);
  tab[16] = NULL;
  return (tab);
}

void	free_all(int fd, char **instr, t_tabinstr *tabinstr,
		 t_instruc *instruc)
{
  close(fd);
  free_tab(instr);
  free(tabinstr->tabinstr);
  free_lablist(&instruc->real_lab);
  free_lablist(&instruc->call_to_lab);
}

int		parser(char *name, t_header *head, t_instruc *instruc)
{
  int		fd;
  t_tabinstr	tabinstr;
  char		**instr;

  instruc->addr_wrt = 0;
  instruc->addr_vir = 0;
  if (create_labcdlist(&instruc->real_lab.root) == 1 ||
      create_labcdlist(&instruc->call_to_lab.root) == 1)
    return (1);
  if ((fd = create_file(name)) == 1)
    return (1);
  instruc->fd = fd;
  if (write_header(fd, head, instruc) == 1)
    return (1);
  init_tabinstr(&tabinstr);
  instr = init_instr();
  if (write_code(fd, instruc, &tabinstr, instr) == 1)
    return (1);
  write_labels(instruc);
  if (write_prog_size(head, instruc, fd) == 1)
    return (1);
  free_all(fd, instr, &tabinstr, instruc);
  return (0);
}
