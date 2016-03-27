/*
** op.h for corewar
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Mon Mar 14 20:56:37 2016 marc brout
** Last update Sun Mar 27 19:20:58 2016 marel_m
*/

#ifndef OP_H_
# define OP_H_

# define MEM_SIZE                (6 * 1024)

/*
** modulo de l'index <
*/

# define IDX_MOD                 512

/*
** this may not be changed 2^*IND_SIZE
*/

# define MAX_ARGS_NUMBER         4
# define COMMENT_CHAR            '#'
# define LABEL_CHAR              ':'
# define DIRECT_CHAR             '%'
# define SEPARATOR_CHAR          ','
# define LABEL_CHARS             "abcdefghijklmnopqrstuvwxyz_0123456789"
# define NAME_CMD_STRING         ".name"
# define COMMENT_CMD_STRING      ".comment"

/*
** regs
** r1 <--> rx
*/

# define REG_NUMBER      16

/*
**
*/

typedef char    t_args_type;

/* T_REG = registre
** T_DIR = directe  (ld  #1,r1  met 1 dans r1)
** T_IND indirecte toujours relatif
** ( ld 1,r1 met ce qu'il y a l'adress (1+pc)
** dans r1 (4 octecs ))
*/

# define T_REG           1
# define T_DIR           2
# define T_IND           4

/*
** LABEL
*/

# define T_LAB           8

typedef struct  s_op
{
   char         *mnemonique;
   char         nbr_args;
   t_args_type  type[MAX_ARGS_NUMBER];
   char         code;
   int          nbr_cycles;
   char         *comment;
}		t_op;

extern t_op op_tab[];

/*
** size en octet
*/

# define IND_SIZE        2
# define REG_SIZE        4
# define DIR_SIZE        REG_SIZE

/*
** header
*/

# define PROG_NAME_LENGTH        128
# define COMMENT_LENGTH          2048
# define COREWAR_EXEC_MAGIC      0xea83f3

/*
** live
** CYCLE_TO_DIE = nombre de cycle pour etre déclarer mort
*/

# define CYCLE_TO_DIE    1536
# define CYCLE_DELTA     4
# define NBR_LIVE        2048

#endif /* !OP_H_ */
