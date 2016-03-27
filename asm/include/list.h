/*
** list.h for LIST in /home/bougon_p/rendu/CPE_2015_corewar/asm
**
** Made by bougon_p
** Login   <bougon_p@epitech.net>
**
** Started on  Wed Mar 23 22:47:58 2016 bougon_p
** Last update Fri Mar 25 17:31:11 2016 marel_m
*/

#ifndef LIST_H_
# define LIST_H_

typedef	struct		s_lablist
{
  char			*name;
  int			addr;
  int			pos;
  int			nb_bytes;
}			t_lablist;

typedef struct          s_cdlist
{
  struct s_lablist	*data;
  struct s_cdlist       *prev;
  struct s_cdlist       *next;
}                       t_cdlist;

typedef struct          s_arglist
{
  t_cdlist              *root;
}                       t_arglist;

int			create_cdlist(t_cdlist *, void *);
int			add_last_cdl(t_cdlist *, void *);
int			free_lablist(t_arglist *);

#endif /* !LIST_H_ */
