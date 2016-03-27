##
## Makefile for ASM in /home/bougon_p/rendu/CPE_2015_corewar/asm
##
## Made by bougon_p
## Login   <bougon_p@epitech.net>
##
## Started on  Thu Mar 10 14:59:56 2016 bougon_p
## Last update Sun Mar 27 19:20:29 2016 bougon_p
##

# USEFUL VARIABLES

RM      =	rm -rf

GREEN	=	\033[1;32m

WHITE	=	\033[0m

ECHO	=	echo -e

# COREWAR VARIABLES

VM		=	corewar/vm/

PARSING		=	corewar/parsing/

LOAD		=	corewar/load_file/

SRCCOR		=	$(PARSING)pars.c \
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
			$(VM)free.c \
			$(VM)get_high_scores.c \
			$(VM)set_vm_memory.c

OBJSCOR    	=	$(SRCCOR:.c=.o)


# ASM VARIABLES

PARSER		=	asm/srcs/parser/

LEXER		=	asm/srcs/lexer/

TOOLS		=	asm/srcs/tools/

ERROR		=	asm/srcs/error/

FREE		=	asm/srcs/free/

SRC		=	asm/srcs/main.c \
			asm/srcs/op.c \
			$(PARSER)parser.c \
			$(PARSER)create_file.c \
			$(PARSER)convert.c \
			$(PARSER)header.c \
			$(PARSER)code.c \
			$(PARSER)live.c \
			$(PARSER)ld.c \
			$(PARSER)st.c \
			$(PARSER)add.c \
			$(PARSER)sub.c \
			$(PARSER)and.c \
			$(PARSER)or.c \
			$(PARSER)xor.c \
			$(PARSER)zjmp.c \
			$(PARSER)ldi.c \
			$(PARSER)sti.c \
			$(PARSER)fork.c \
			$(PARSER)lld.c \
			$(PARSER)lldi.c \
			$(PARSER)lfork.c \
			$(PARSER)aff.c \
			$(PARSER)code_byte.c \
			$(PARSER)w_args.c \
			$(PARSER)labs.c \
			$(PARSER)initlist.c \
			$(LEXER)lexer.c \
			$(LEXER)check_name.c \
			$(LEXER)check_comment.c \
			$(LEXER)check_instructions.c \
			$(LEXER)check_label.c \
			$(LEXER)check_registre.c \
			$(LEXER)epure_file.c \
			$(LEXER)put_in_list.c \
			$(LEXER)check_char.c \
			$(LEXER)check_stock.c \
			$(LEXER)check_if_label_exist.c \
			$(LEXER)verif_args.c \
			$(LEXER)instruc_three_args.c \
			$(LEXER)reg_regdirin_regdir.c \
			$(LEXER)regdirin_regdir_reg.c \
			$(LEXER)regdirin_regdirin_reg.c \
			$(LEXER)check_good_args.c \
			$(TOOLS)str_null.c \
			$(TOOLS)my_strcat.c \
			$(TOOLS)my_strncmp.c \
			$(TOOLS)my_strndup.c \
			$(TOOLS)my_put_nbr_error.c \
			$(TOOLS)overflow.c \
			$(FREE)free_tab.c \
			$(FREE)free_list_instruc.c \
			$(ERROR)error_stop.c \
			$(ERROR)error.c

OBJS    	=	$(SRC:.c=.o)


# LIBRARY VARIABLES

LIBPATH =       lib/

LIB	=	lib/libmy.a

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

NAME	=	asm/asm

COREWAR =	corewar/corewar

IFLAG	=	-Iasm/include/ -Icorewar/include/

CFLAGS  =	-W -Wall -Wextra

CC      =	gcc $(CFLAGS) $(IFLAG)


# PROJECT RULES

$(NAME)		: 	$(LIB) $(COREWAR) $(OBJS)
			@$(ECHO) "$(GREEN)\n>>>>>>>>>>>>>>>>\n\n> Linking \"$(NAME)\"\n\twith \
\"$(CC)\"\n\n>>>>>>>>>>>>>>>\t DONE\n$(WHITE)"
			@$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

$(COREWAR)	:	$(OBJSCOR)
			@$(ECHO) "$(GREEN)\n>>>>>>>>>>>>>>>\n\n> Linking \"$(COREWAR)\"\n\twith \"$(CC)\"\n\n>>>>>>>>>>>>>>> \t DONE\n$(WHITE)"
			@$(CC) -o $(COREWAR) $(OBJSCOR) $(LDFLAGS)

$(LIB)		:	$(OBJSLIB)
			@ar rc $(LIB) $(OBJSLIB)
			@ranlib $(LIB)
			@$(ECHO) "$(GREEN)\n> Compiling Library\t >>>>>>>>>>>>>>> \t DONE\n$(WHITE)"


all		:	$(NAME)

clean		:
			@$(RM) $(OBJS)
			@$(RM) $(OBJSLIB)
			@$(RM) $(OBJSCOR)
			@$(ECHO) "$(GREEN)\n> Cleaning repository\t >>>>>>>>>>>>>>> \t DONE\n$(WHITE)"

fclean		: 	clean
			@$(RM) $(NAME)
			@$(RM) $(COREWAR)
			@$(RM) $(LIBPATH)/libmy.a
			@$(ECHO) "$(GREEN)\n> Cleaning exec\t\t >>>>>>>>>>>>>>> \t DONE\n$(WHITE)"

re		:	fclean all

.c.o		:
			@$(CC) -c $< -o $@
			@$(ECHO) "$(GREEN)[OK] > $<\t \t $(WHITE)"
