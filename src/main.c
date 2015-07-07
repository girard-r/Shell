/*
** main.c for 42sh in /home/vadee_s/rendu/42sh/42sh
** 
** Made by vadee
** Login   <vadee_s@epitech.net>
** 
** Started on  Wed Apr 23 18:41:34 2014 vadee
** Last update Sun Jun  1 17:32:47 2014 jolivald
*/

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "trunc.h"
#include "parser.h"
#include "lexer.h"

int	g_is_env;

char		**my_branch(char *s, char **env, int *j)
{
  t_liste	*list;
  t_env		envs;

  envs.env = env;
  envs.path = NULL;
  envs.path = parse_path(env);
  if ((list = get_entry(s, envs.path, env)) != NULL)
    {
      fill_parser(list, &envs);
    }
  add_history(s);
  *j = 0;
  return (envs.env);
}

int		my_trunc(char **env, int j, struct termios *term)
{
  char		*s;

  set_prompt(env, 1);
  if_signal();
  while ((s = get_command_line(0, term)))
    {
      my_putchar(10);
      if (s[0] != 0 && (env = my_branch(s, env, &j)) == NULL)
	return (0);
      set_prompt(env, 0);
    }
  return (-1);
}

int			init_shell(char **env)
{
  int			j;
  struct termios	term;
  struct termios	init;

  j = 0;
  if (isatty(0) == 0
      || init_termcaps(&term, &init, env) == -1)
    g_is_env = 1;
  my_trunc(env, j, &term);
  if (g_is_env == 0 && tcsetattr(0, 0, &init) == -1)
    return (-1);
  return (0);
}

int		main(int argc, char **argv, char *envp[])
{
  char		**env;

  if (argc != 1 || argv[1] != NULL)
    {
      printf("USAGE : ./42\n");
      return (-1);
    }
  else if ((env = cp_env(envp, 0)) == NULL)
    {
      printf("MALLOC ERROR");
      return (-1);
    }
  else if (init_shell(env) == -1)
    return (-1);
  return (0);
}
