/*
** parser.h for parser.h in /home/girard_r/42sh/parser
** 
** Made by girard_r
** Login   <girard_r@epitech.net>
** 
** Started on  Fri May  9 23:43:31 2014 girard_r
** Last update Sun Jun  1 22:32:19 2014 jolivald
*/

#ifndef PARSER_H_
# define PARSER_H_

# define OP_MAX 4
# include <lexer.h>

# define RIGHT     0b00000001
# define LEFT      0b00000010
# define DBLEFT    0b00000110
# define SON_RIGHT 0b00010000
# define DONE      0b00001000

typedef struct		s_command
{
  char			**new_argv;
  int			pipefd[2];
  int			pid;
  char			is_builtin;
}			t_command;

typedef struct		s_parser
{
  char			*data;
  struct s_command	*command;
  struct s_parser	*son;
  struct s_parser	*father;
}			t_parser;

typedef struct		s_priorities
{
  char			*operator;
  int			priority;
}			t_priorities;

typedef struct		s_env
{
  char			**env;
  char			**path;
}			t_env;

typedef struct		s_function
{
  char			*operator;
  char			**(*f_ptr)();
}			t_function;

/*
** parser.c
*/

int		add_in_parser(char *elem, t_parser **father);
int		add_token(t_liste *params, t_parser **parser);
int		add_command(t_parser *parser, char **new_argv, t_liste *param);
int		fill_command(t_liste **list, t_parser *parser);
int		fill_parser(t_liste *params, t_env *envs);
t_parser	*init_parser(char *elem);

/*
** my_realloc_tab.c
*/

char		*my_strcpy(char *dest, char *src);
char		*my_strdup(char *src);
int		tab_len(char **tab);
char		**my_realloc_add(char **model, char *str);

/*
** priority.c
*/

int		get_prio_op(char *op);
int		check_priorities(t_liste *param, t_parser *parser);

/*
** process_exec.c
*/

int		process_command_line(t_parser **parser, t_env *envs, int *status, char *redir);
int		exec_cmd(t_parser *parser, t_env *envs);

/*
** free.c
*/

int		free_tab(char **tab);
int		free_parser(t_parser *parser);

/*
** test.c
*/

int		test_redir(t_parser **parser, char *redir);
int		test_pipe(t_parser *parser, char redir);

/*
** process_command_loop.c
*/

int		process_command_loop(t_parser *parser, t_env *envs);
t_parser	*fork_loop(t_parser *parser, int *ex_status, t_env *envs);
int		open_pipes(t_parser *parser);
void		get_allowed(t_parser *tmp, char *allowed, int *ex_status);

/*
** fill_parser.c
*/

int		fill_parser(t_liste *params, t_env *envs);
int		test_token(int *ret, t_liste **tmp,
			   t_parser **parser, t_env *envs);
int		fill_command(t_liste **params, t_parser *parser);

/*
** redir.c
*/

t_parser	*get_parent_cmd(t_parser *current);
int		test_single_right(t_parser *parser, char *redir);
int		get_error(const char *str);
int		test_double_right(t_parser *parser, char *redir);
int		test_single_left(t_parser *parser, char *redir);

/*
** double_left.c
*/

int		process_double_left(char *redir, t_parser *parser,
				    int *tmpipe, t_parser *cmpd);
int		test_double_left(t_parser *parser, char *redir);

/*
** get_only_cmd.c
*/

void		get_only_cmd(t_parser **parser);
void		get_only_cmd_custom(t_parser **parser);
void		smallymize(t_parser **parser);

/*
** exec_sh.c
*/

int		check_for_access_exec(char *filename);
int		check_for_exec(char **new_av, char **envp);
int		check_path_exec(char **new_av, char **envp, char **path);

int		my_strlen(char *str);

#endif /* !PARSER_H_ */
