##
## Makefile for  in /home/brout_m/RENDU/CPE/CPE_2015_corewar/vm
## 
## Made by marc brout
## Login   <brout_m@epitech.net>
## 
## Started on  Mon Mar 21 23:17:37 2016 marc brout
## Last update Sun Mar 27 00:20:22 2016 marc brout
##

# USEFUL VARIABLES

RM      =	rm -rf

GREEN	=	\033[1;32m

WHITE	=	\033[0m

ECHO	=	echo -e


# SOURCES VARIABLES

VM		=	vm/

PARSING		=	parsing/

LOAD		=	load_file/

SRC		=	$(PARSING)pars.c \
			$(PARSING)prog_number.c \
			$(PARSING)order_champ.c \
			$(PARSING)list_arg.c \
			$(PARSING)my_getnbr.c \
			$(PARSING)func_arg.c \
			$(PARSING)nothing.c \
			$(PARSING)add.c \
			$(PARSING)aff.c \
			$(PARSING)and.c \
			$(PARSING)fork.c \
			$(PARSING)lfork.c \
			$(PARSING)ld.c \
			$(PARSING)ldi.c \
			$(PARSING)live.c \
			$(PARSING)lld.c \
			$(PARSING)lldi.c \
			$(PARSING)or.c \
			$(PARSING)xor.c \
			$(PARSING)sub.c \
			$(PARSING)st.c \
			$(PARSING)sti.c \
			$(PARSING)zjump.c \
			$(LOAD)load_file.c \
			$(LOAD)my_bzero.c \
			$(VM)vm.c \
			$(VM)read_from_ram.c \
			$(VM)launch_match.c \
			$(VM)dump.c \
			$(VM)init.c \
			$(VM)run_one_cycle.c \
			$(VM)misc.c \
			$(VM)get_high_scores.c \
			$(VM)set_vm_memory.c \
			$(VM)free.c

OBJS    	=	$(SRC:.c=.o)


# LIBRARY VARIABLES

LIBPATH =       ../lib/

SRCLIB	=	$(LIBPATH)my/get_next_line.c \
		$(LIBPATH)my/my_getnbr.c \
		$(LIBPATH)my/my_power_rec.c \
		$(LIBPATH)my/my_printf.c \
		$(LIBPATH)my/my_printfcsspb.c \
		$(LIBPATH)my/my_printfdiouxx.c \
		$(LIBPATH)my/my_printfmetc.c \
		$(LIBPATH)my/my_putchar.c \
		$(LIBPATH)my/my_put_nbr.c \
		$(LIBPATH)my/my_putstr.c \
		$(LIBPATH)my/my_revstr.c \
		$(LIBPATH)my/my_strcmp.c \
		$(LIBPATH)my/my_strdup.c \
		$(LIBPATH)my/my_strlen.c \
		$(LIBPATH)my/my_strncmp.c \

LDFLAGS =       -lmy -L$(LIBPATH)

OBJSLIB	=	$(SRCLIB:.c=.o)

# PROJECT VARIABLES

NAME	=	corewar

IFLAG	=	-Iinclude/ -I../asm/include

DEBUG	=	-g

CFLAGS  =	$(DEBUG) -W -Wall -Wextra $(IFLAG)

CC      =	gcc $(CFLAGS)



# PROJECT RULES

$(NAME)		: 	$(OBJSLIB) $(OBJS)
			@ar rc $(LIBPATH)libmy.a $(OBJSLIB)
			@ranlib $(LIBPATH)libmy.a
			@$(ECHO) "$(GREEN)\n>>>>>>>>>>>>>>>>\n \
Compiling \"$(NAME)\" project with \"$(CC)\"\t \
\n>>>>>>>>>>>>>>> \t DONE\n$(WHITE)"
			@$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

all		:	$(NAME)

clean		:
			@$(RM) $(OBJS)
			@$(RM) $(OBJSLIB)
			@$(ECHO) "$(GREEN)\n> Cleaning repository\t \
>>>>>>>>>>>>>>> \t DONE\n$(WHITE)"

fclean		: 	clean
			@$(RM) $(NAME)
			@$(RM) $(LIBPATH)/libmy.a
			@$(ECHO) "$(GREEN)\n> Cleaning exec\t\t \
>>>>>>>>>>>>>>> \t DONE\n$(WHITE)"

re		:	fclean all

.c.o		:
			@$(CC) -c $< -o $@
			@$(ECHO) "$(GREEN)[OK] > $<\t \t $(WHITE)"
