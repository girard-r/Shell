##
## Makefile for  in /home/girard_r/42sh
## 
## Made by girard_r
## Login   <girard_r@epitech.net>
## 
## Started on  Sun May 25 01:01:58 2014 girard_r
## Last update Sun Jun  1 18:57:14 2014 jolivald
##

LEXER	=	src/lexer/

TCAPS	=	src/termcaps/

UTILS	=	src/utils/

PARSER	=	src/parser/

BUILTIN	=	src/builtins/

SRC	=	$(LEXER)check_type.c \
		$(LEXER)count_token.c \
		$(LEXER)check_order.c \
		$(LEXER)order_types.c \
		$(LEXER)define_type.c \
		$(LEXER)env_variables.c \
		$(LEXER)get_entry.c \
		$(LEXER)init_list.c \
		$(LEXER)parse_builtins.c \
		$(LEXER)parse_path.c \
		$(LEXER)parse_separators.c \
		$(LEXER)parse_tokens.c \
		$(LEXER)process_error_lexer.c \
		$(LEXER)regroup_args.c \
		$(TCAPS)get_command_line.c \
		$(TCAPS)misc.c \
		$(TCAPS)add_autocpl.c \
		$(TCAPS)my_termcaps.c \
		$(TCAPS)modif_term.c \
		$(UTILS)cp_env.c \
		$(UTILS)suppr_elem_list.c \
		$(UTILS)my_putstr.c \
		$(UTILS)my_strlen.c\
		$(UTILS)my_signal.c \
		$(UTILS)my_str_to_wordtab_sh.c \
		$(UTILS)my_str_to_wordtab_path.c \
		$(UTILS)set_prompt.c \
		$(PARSER)redir.c \
		$(PARSER)get_only_cmd.c \
		$(PARSER)exec_sh.c \
		$(PARSER)process_exec.c \
		$(PARSER)parser.c \
		$(PARSER)my_realloc_tab.c \
		$(PARSER)priority.c \
		$(PARSER)double_left.c \
		$(PARSER)fill_parser.c \
		$(PARSER)free.c \
		$(PARSER)test.c \
		$(PARSER)process_command_loop.c \
		$(BUILTIN)add_history.c \
		$(BUILTIN)builtin_echo.c \
		$(BUILTIN)builtin_exit.c \
		$(BUILTIN)builtin_history.c \
		$(BUILTIN)builtin_main.c \
		$(BUILTIN)builtin_realloc.c \
		$(BUILTIN)builtins.c \
		$(BUILTIN)getenv.c \
		$(BUILTIN)get_next_line.c \
		$(BUILTIN)my_str_to_wordtab2.c \
		$(BUILTIN)search_history.c \
		$(BUILTIN)b_setenv.c \
		$(BUILTIN)funcs_setenv.c \
		$(BUILTIN)funcs_2_setenv.c \
		$(BUILTIN)b_unsetenv.c \
		$(BUILTIN)b_env.c \
		src/main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	mysh

CFLAGS	=	-I./inc/ -Wall -Wextra -g3

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) -lncurses
clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
