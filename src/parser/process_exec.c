/*
** process_exec.c for process_exec in /home/girard_r/42sh/parser
** 
** Made by girard_r
** Login   <girard_r@epitech.net>
**
** Started on  Thu May 22 21:39:27 2014 girard_r
** Last update Sun Jun  1 22:17:25 2014 jolivald
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "parser.h"
#include "lexer.h"
#include "builtin.h"

int		close_pipes(t_parser *parser)
{
  t_parser	*tmp;

  tmp = parser;
  while (tmp)
    {
      if (strcmp(tmp->data, "|") == 0
	  && (close(tmp->command->pipefd[0]) == -1 ||
	      close(tmp->command->pipefd[1]) == -1))
	  return (-1);
      tmp = tmp->father;
    }
  return (1);
}

int		exec_cmd(t_parser *parser, t_env *envs)
{
  t_command	*cmd;

  close_pipes(parser->father);
  cmd = parser->command;
  if (check_for_exec(cmd->new_argv, envs->env) == -1
      || (envs->path
	  && check_path_exec(cmd->new_argv, envs->env, envs->path) == -1))
    return (-1);
  return (0);
}

int		process_command_line(t_parser **parserp, t_env *envs,
				     int *status, char *redir)
{
  pid_t		pid;
  t_parser	*tmp;

  tmp = *parserp;
  if (strcmp(tmp->data, "|") == 0
      && pipe(tmp->command->pipefd) == -1)
    return (-1);
  if (tmp->command->is_builtin == 1)
    return (select_builtin(tmp->command->new_argv, envs, status));
  if ((pid = fork()) == 0)
    {
      if (test_redir(&tmp, redir) == -1 ||
	  test_pipe(tmp, *redir) == -1 ||
	  exec_cmd(tmp, envs) == -1)
	return (-1);
    }
  else if (pid > 0)
    {
      get_only_cmd_custom(parserp);
      (*parserp)->command->pid = pid;
      return (0);
    }
  else
    perror("Fork Error");
  return (0);
}
