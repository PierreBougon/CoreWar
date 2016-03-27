/*
** vm.h for vm
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Mon Mar 21 10:36:14 2016 marc brout
** Last update Sun Mar 27 00:51:31 2016 marc brout
*/

#ifndef VM_H_
# define VM_H_

# include "asm.h"
# include "op.h"

/*
** ERROR OUTPUTS
*/

# define OVERLAP "Overlap detected.\n"
# define MALLOC_ERROR "Can't perform malloc\n"
# define NOCOREWAR " is not a corewar executable\n"
# define CORRUPT " is corrupted\n"
# define MISS_COR "Missing corewar executable\n"

# define IDX(x) ((x) % IDX_MOD)
# define M(x) ((x) % MEM_SIZE)
# define MM(x) ((x) % MEM_SIZE)
# define IDX(x) ((x) % IDX_MOD)
# define RSFM read_short_from_ram
# define RIFM read_int_from_ram
# define RUIFM read_uint_from_ram

char		g_endian;

typedef enum		e_instructions
  {
    VM_ERROR		= 0,
    VM_LIVE		= 1,
    VM_LD		= 2,
    VM_ST		= 3,
    VM_ADD		= 4,
    VM_SUB		= 5,
    VM_AND		= 6,
    VM_OR		= 7,
    VM_XOR		= 8,
    VM_ZJMP		= 9,
    VM_LDI		= 10,
    VM_STI		= 11,
    VM_FORK		= 12,
    VM_LLD		= 13,
    VM_LLDI		= 14,
    VM_LFORK		= 15,
    VM_AFF		= 16
  }			t_instructions;

typedef struct		s_val
{
  int			type[3];
  short			shrt[3];
  int			inte[3];
}			t_val;

typedef struct		s_inst
{
  unsigned		fi;
  unsigned		sd;
  unsigned		th;
}			t_inst;

typedef union		s_core_int
{
  unsigned int		value;
  unsigned char		bytes[4];
}			t_core_int;

typedef union		s_core_short
{
  unsigned short	value;
  unsigned char		bytes[2];
}			t_core_short;

typedef	struct		s_pc
{
  int			carry;
  unsigned int		reg[16];
  int			cycle;
  char			run;
  struct s_champion	*champ;
  struct s_pc		*next;
}			t_pc;

typedef struct		s_champion
{
  char			*path;
  char			valid;
  int			alive;
  int			order;
  unsigned int		size;
  char			name[PROG_NAME_LENGTH + 1];
  t_pc			*pc;
}			t_champion;

typedef struct		s_data
{
  int			nblive;
  int			last;
  int			dump;
  int			i;
  t_champion		*champ[4];
  int			(*inst[17])(struct s_data *, t_pc *);
  char			*ram;
}			t_data;

typedef struct		s_pars
{
  char			*arg;
  int			(*chk_arg)(char **, int *, t_data *);
  struct s_pars		*next;
}			t_pars;

/*
** dump.c
*/

void			dump(char *ram);
void			octect_to_base(char octect,
				       char hexa[2],
				       char *base);

/*
** load_file.c
*/

void			my_bzero(void *ptr, int size, char val);
char			endianness();
int			swap_integer(int nb);
int			check_header(int fd, t_header *head);
void			copy(char *src, char *dst);
int			init_champs(t_data *data);
int			load_champion(t_champion *champion,
				      char *champion_file);

/*
** vm.c
*/

int			my_put_file_str(const char *file,
					const char *str,
					int err);
int			my_put_file_noaccess(const char *file,
					     int err);
int			my_put_error(const char *str,
				     int err);
int			my_put_usage(char **av,
				     int err);

/*
** misc.c
*/

void			my_putnbr_tofd(int nb, int fd);
int			my_strlencst(const char *str);
int			my_mystrcmpcst(const char *str1,
				       const char *str2);
int			my_revstrncmpcst(const char *str1,
					 const char *str2,
					 int n);
char			*my_strcatcst(const char *str1,
				      const char *str2);
char			*get_name(const char *str1,
				  const char *str2);
/*
** set_vm_memory.c
*/

int			init_ram(t_data *data);
int			copy_champion_to_ram(t_champion *champion,
					     char *ram);
int			size_champs(t_champion *champ[4],
				    int first,
				    int *nb);
int			place_all_champions(t_data *data);

/*
** check arguments function: func_arg.c
*/

int			check_arg(char **, int *, t_pars *, t_data *);
int			chk_adress(char **, int *, t_data *);
int			chk_dump(char **, int *, t_data *);
int			chk_prog_nbr(char **, int *, t_data *);

/*
** list arguments : list_arg.c
*/

int			add_adress_in_list(t_pars *);
int			add_dump_in_list(t_pars *);
int			add_prog_nbr_in_list(t_pars *);
t_pars			*init_list();

/*
** annex_function.
*/

int			my_getnbr_prog(char *);
int			my_strcmp(char *, char *);

/*
** list champion: order_champ.c
*/

void			order_champ(t_data *);
void			swap_champ(t_data *, int);

/*
** begin parsing arguments: pars.c
*/

int			my_put_int_error(int, int);
int			pars_arg(char **, t_pars  *, t_data *);

/*
** order my champ: prog_number.c
*/

int			check_prog_number_value(t_data *);
void			put_order_in_champ(t_data *, int);
void			recheck_prog_number(t_data *);

/*
** st.c
*/

int			check_integrety_st(unsigned, char *, int);
int			st(t_data *, t_pc *);
void			move_pc_st(unsigned, t_pc *);

/*
** live.c
*/

int			live(t_data *, t_pc *);

/*
** ld && lld: ld.c && lld.c
*/

int			check_integrety_ld(unsigned, char *, int);
int			ld(t_data *, t_pc *);
int			lld(t_data *, t_pc *);
void			move_pc_ld(unsigned, t_pc *);

/*
** add && sub: add.c && sub.c
*/

int			add(t_data *, t_pc *);
int			sub(t_data *, t_pc *);

/*
** and / or / xor : and.c && or.c && xor.c
*/

int			recup_val(t_data *, t_pc *, t_inst *, t_val *);
int			and(t_data *, t_pc *);
int			check_integrety(unsigned, unsigned, char *, int);
int			or(t_data *, t_pc *);
int			xor(t_data *, t_pc *);
void			move_pc(unsigned, unsigned, t_pc *);

/*
** zjmp: zjump.c
*/

int			zjump(t_data *, t_pc *);

/*
** ldi && lldi: ldi.c && lldi.c
*/

int			check_integrety_ldi(unsigned, unsigned, char *, int);
int			ldi(t_data *, t_pc *);
int			lldi(t_data *, t_pc *);
void			move_pc_ldi(unsigned, unsigned, t_pc *);

/*
** sti: sti.c
*/

int			check_integrety_sti(unsigned, unsigned, char *, int);
int			sti(t_data *, t_pc *);
void			move_pc_sti(unsigned, unsigned, t_pc *);

/*
** fork / lfork : fork.c && lfork.c
*/

int			can_i_run(t_pc *, int);
int			frk(t_data *, t_pc *);
int			lfork(t_data *, t_pc *);

/*
** aff : aff.c
*/

int			aff(t_data *, t_pc *);

/*
** nothing: nothing.c
*/

int			nothing(t_data *, t_pc *);

/*
** run_one_cycle.c
*/

int			run_one_cycle(t_data *data);
int			launch_one_champ_pc(t_data *, t_champion *,
					    int, char *);
int			test_instruction(t_data *, t_pc *);
int 			ready_to_cycle(t_data *);

/*
** launch_match.c
*/

int			count_players_alive(t_champion *champ[4]);
void			set_players(t_champion *champ[4]);
void			check_winner(t_data *data,
				     t_champion *champ[4]);
int			launch_match(t_data *data);
void			copy_order_to_reg(t_champion *champ[4]);

/*
** init.c
*/

int			add_pc(t_pc *, int, int);
void			copy_registres(t_pc *, t_pc *);
void			init_inst(t_data *);

/*
** read_from_ram.c
*/

int			read_int_from_ram(char *ram,
					  int pos);
unsigned int		read_uint_from_ram(char *ram,
					  int pos);
short			read_short_from_ram(char *ram,
					    int pos);
void			write_int_to_ram(char *ram,
					 unsigned int val,
					 int pos);
void			write_short_to_ram(char *ram,
					   unsigned short val,
					   int pos);

/*
** free.c
*/

void			free_args(t_pars *root);
void			free_data(t_data *data);

#endif /* !VM_H_ */
