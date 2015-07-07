/*
** mysh.h for mysh.h in /home/girard_r/Documents/PSU_2013_minishell1
** 
** Made by girard_r
** Login   <girard_r@epitech.net>
** 
** Started on  Tue Dec 10 15:39:29 2013 girard_r
** Last update Tue May 27 21:25:00 2014 jolivald
*/

#ifndef MY_SH_H_
# define MY_SH_H_

typedef struct	s_builtins
{
  char	*builtin;
  int	(*ptrf)();
}		t_built;

typedef struct	s_env
{
  char	*bu_env;
  char	**(*ptrf)();
}		t_env;

typedef struct	s_redir
{
  int		*pos;
  char		*r_type;
  int		o_flag;
  int		nb_redir;
}		t_redir;

typedef struct	s_pipe
{
  t_redir	*redir;
  int		pipefd[2];
  int		nb_pipe;
  int		file_fd;
}		t_pipe;

char	**my_str_to_wordtab(char *s);
char	**my_str_to_wordtab_sh(char *s);
char	*my_strdup(char *src);
char	*get_home(char **envp);
int	free_tab(char **tab);
int	builtin_cd(char **new_av, char **envp, char *s, t_built *built);
int	builtin_env(char **new_av, char **envp, char *s, t_built *built);
int	builtin_exit(char **temp_env, char **new_av, char *s, t_built *built);
char	**builtin_setenv(char **new_av, char **envp);
int	builtins(char **new_av, char **envp, char *s);
int	check_for_exec(char **new_av, char **envp);
int	check_for_exec_in_path(char **new_av, char **envp, char **path);
char	**get_path(char **envp);
int	mysh(char **new_av, char **envp, char *s, t_pipe *pipe);
char    **get_my_env(char **envp);
char	**my_realloc_add(char **envp, char *name, char *value);
int	check_if_name(char *name, char **envp);
char    **check_builtin_env(char **tmp_env, char **new_av, int *cmp);
char	**my_realloc_less(char **envp, int pos);
char	**builtin_unsetenv(char **new_av, char **envp);
char	**process_mysh(char *s, char **tmp_env, char **new_av);
int	process_son(char **new_av, char **envp, char **path);
char	**my_change_env(char **envp, char *name, char *value, int pos);
t_built	*get_built();
t_env	*get_built_env();
int	get_signal();
void	process_signal(int signal);
char	**parse_pipe(char **new_av);
t_redir	*init_redir();
char	**parse_coma(char **new_av);
char	**process_mysh(char *s, char **tmp_env, char **new_av);
char	**choose_process(char *s, char **tmp_env);
char	**parse_redir(char **new_av);
t_pipe	*my_malloc_pos(int cmp0, int cmp1, int cmp2, t_pipe *pipe);
int	get_redir(t_pipe *pipe, int cmp);
t_pipe	*process_mysh_redir(char **new_av, char *s,
			    char **tmp_env, t_pipe *pipe);
void	init_var_redir(int *cmp0, int *cmp1,
		       int *cmp2, int *i);
t_pipe	*count_redir(char **new_av, t_pipe *pipe);
t_redir	*empty_redir(t_redir *redir, char **new_av);
t_pipe	*init_pipe();

#endif /* !MY_SH_H_ */
