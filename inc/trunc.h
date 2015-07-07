/*
** trunc.h for 42sh in /home/vadee_s/rendu/42sh
** 
** Made by vadee_s
** Login   <vadee_s@epitech.net>
** 
** Started on  Fri May  9 19:12:19 2014 vadee_s
** Last update Sat May 31 23:50:21 2014 jolivald
*/

#ifndef TRUNC_H_
# define TRUNC_H_
# include <termios.h>

extern int	g_is_env;

char		*search_history(int pos);
int		add_history(char *cmd);
char		*auto_comp(char *str, char **envp, int *src, char *s);
int		my_putchar(int c);
void		my_putstr(char *str);
int		init_shell(char **env);
int		set_prompt(char *env[], int line);
int		if_signal();

/*
 * misc.c
 */

int		is_interactive(int isenv, char *s);
char		*check_cmd_line(char *tmp, int ret);

/*
 * add_autocpl.c
 */
int		puts_end(char *tmp, int *i);
int		end_autocpl(char *tmp, char *autocpl, int *i, struct termios *term);
int		putchar_in_string(char *str, char c, int i);

char		**my_branch(char *s, char **env, int *j);
int		my_trunc(char **env, int j, struct termios *term);
int		init_shell(char **env);
int		main(int ac, char **av, char *envp[]);
char		**parse_path(char **env);
char		*get_command_line(int fd, struct termios *term);
char		**cp_env(char **envp, int i);

/*
 * termcaps
 */

void		clean_buff(char *s);
int		is_printable(char *s);
char		*init_get_cmd(int fd, struct termios *term, char *s, char *tmp);
int		delete_char(char *tmp, int *i);
char		*my_use_screen(char mode, char *str, int *i);
int		mov_curs(char *tmp, char way, int *i);
char		*my_curs(char *s, char *tmp, int *i);
char		*print_char(char *tmp, char c, int *i, struct termios *term);
int		init_termcaps(struct termios *term,
			      struct termios *init, char **env);
int		raw_mode(struct termios *term);
int		print_mode_off(struct termios *term);
int		print_mode_on(struct termios *term);

#endif /* ! TRUNC_H_ */
