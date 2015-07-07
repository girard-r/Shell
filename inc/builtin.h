/*
** builtin.h for 42sh in /home/grout_r/rendu/42sh/42sh/builtins
** 
** Made by roman grout
** Login   <grout_r@epitech.net>
** 
** Started on  Mon May  5 14:29:11 2014 roman grout
** Last update Sun Jun  1 17:26:26 2014 jolivald
*/

#ifndef BUILTIN_H_
# define BUILTIN_H_

typedef struct		s_built
{
  char			*cmd;
  char			**(*funcptr)(char**, char **, int *);
}			t_built;

typedef struct		s_backslash
{
  char			escape;
  char			occurence;
}			t_backslash;

typedef struct	s_env	t_env;

/*
** my_str_to_wordtab2.c
*/

int			total_words2(char *str);
int			fill_tab2(char **b_tab, char *str, int pos, int pos_next);
char			**my_str_to_wordtab2(char *str);

/*
** search_history.c
*/

char			*search_cmd(char **history, int pos);
char			*search_history(int pos);

/*
** get_next_line.c
*/

char			*myaddstr(char *str, int i);
char			*get_next_line(const int fd);

/*
** unalias.c
*/

char			**b_unalias(char **arg, char **env, int *ret);

/*
** builtin_realloc.c
*/

int			b_tab_len(char **b_tab);
char			**my_realloc_env(char **envp, char *name, char *value, int *ret);
char			**my_realloc_less(char **envp, int pos, int *ret);
char	       		**back_path(char **env);
char			**check_for_access_cd(char *filename, int flag, char **envp, int *ret);

/*
** builtin_history.c
*/

char			**b_history(char **arg, char **env, int *ret);

/*
** builtin_echo.c
*/

char			*print_escape(char *str);
void		       	normal(char **arg);
void			with_escapes(char **arg);
char			**b_echo(char **arg, char **env, int *ret);

/*
** add_history.c
*/

int			my_putfile(char a, int fd);
void			my_put_nbr_file(int nb, int fd);
int			add_one(int fd, char *cmd, int pos);
int			add_history(char *cmd);

/*
** builtin_alias.c
*/

int			print_alias(void);
int			write_alias(char **arg);
char			**b_alias(char **arg, char **env, int *ret);

/*
** builtin_exit.c
*/

void			b_free_tab(char **b_tab);
char			**b_exit(char **arg, char **env, int *ret);

/*
** builtin_main.c
*/

int			select_builtin(char **data, t_env *envs, int *status);

/*
** builtins.c
*/

int			change_pwd(char **envp, char *filename);
char			**builtin_cd(char **new_av, char **envp, int *ret);

/*
** getenv.c
*/

char			*get_home(char **envp);
char			**check_if_oldpath(char **envp, int *ret);
int			test_exists(char **envp, char *name);
char			**my_change_env(char **envp, char *name, char *value, int *ret);

/*
** is_alias.c
*/

char			*find_cmd(char *str, int *done);
char			*is_alias(char *str);

/*
** SETENV
*/

char	**do_b_setenv(char **entry, char **env, int *status);
char	*do_setenv_overwrite(char *env, char *value, char *name, int *status);
int	is_env_exist(char *param, char **env);
char	*get_env(char *name, char *value);
void	free_env(char **env);
char	**do_setenv(char **env, char *value, char *name, int *status);
char	**dispatch_setenv(char **env, char *value, char *name, int *i);

/*
** b_unsetenv.c
*/

char	**do_b_unsetenv(char **entry, char **env, int *status);
char	**second_part_unsetenv(char **env, char **params, int *status);
int	my_strequalncmp(char *str1, char *str2, int n);

/*
** b_env.c
*/

char	**do_b_env(char **entry, char **env, int *status);

#endif /* BUILTIN_H_ */
