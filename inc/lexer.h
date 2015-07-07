/*
** lexer.h for 42sh in /home/grout_r/rendu/42sh/42sh/lexer
** 
** Made by roman grout
** Login   <grout_r@epitech.net>
** 
** Started on  Wed Apr 23 21:43:57 2014 roman grout
** Last update Sun Jun  1 14:13:55 2014 jolivald
*/

#ifndef LEXER_H_
# define LEXER_H_

# define BUILTIN 0
# define TOKEN 1
# define SEPARATOR 4
# define CMD 2
# define OTHER 3

typedef struct          s_liste
{
  char                  *data;
  int			type;
  struct s_liste        *next;
  struct s_liste        *prev;
}                       t_liste;

typedef struct		s_ptrfunc
{
  int			type;
  int			(*fptr)(t_liste*);
}			t_ptrfunc;

int		my_putchar(int c);
void		my_putstr(char *str);

/*
 * order_types.c
 */

int		invers_syntax(t_liste *tmp);

int		if_builtin(t_liste *list);
int		if_separator(t_liste *list);
int		if_token(t_liste *list);
int		if_cmd(t_liste *list);
int		if_other(t_liste *list);

void		suppr_elem_list(t_liste *elem);

int		check_order(t_liste *list);

int		count_tokens(t_liste *list);
int		count_braces(t_liste *list);
int		count_parenthesis(t_liste *list);
int		count_quotes(t_liste *list);
int		process_error(t_liste *list);
void		define_type(t_liste *racine, char **path);
void		define_type_loop(t_liste *tmp, char **path);
int		is_builtin(char *str);
int		is_token(char *str);
int		is_separator(char *str);
int		path_exe(char *str);
int		is_cmd(char *str, char **path);
t_liste		*get_entry(char *str, char **path, char **env);
void		print_list(t_liste *list);
int		fill_tab(char **tab, char *str, int pos, int pos_next);
int		total_words(char *str);
char		**my_str_to_wordtab_sh(char *str);
char		**my_str_to_wordtab_path(char *str);
t_liste		*add_elem_in_list(t_liste *racine, char *str, int ndup);
t_liste		*linked_list(char **cmd);
char		**pars_env(char **env);
t_liste		*check_if_token(t_liste *list, char **cmd, int j, int *k);
t_liste		*check_if_separator(t_liste *list, char **cmd, int j, int *k);
t_liste		*parse_entry(t_liste *list, char **cmd, int *j);
t_liste		*replace_env_variable(t_liste *tmp, char **env);
t_liste		*find_env_variables(t_liste *list, char **env);

void		swap_elems(t_liste *t1, t_liste *t2);

t_liste		*regroup_args(t_liste *list);
t_liste		*fill_args_list(t_liste *list);
#endif /* ! LEXER_H_ */
