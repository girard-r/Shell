/*
** process_command_loop.c for 42sh in /home/joliva_d/rendu/42sh/src/parser
** 
** Made by jolivald
** Login   <joliva_d@epitech.net>
** 
** Started on  Sun Jun  1 18:27:58 2014 jolivald
** Last update Sun Jun  1 22:32:21 2014 jolivald
*/

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "parser.h"
#include "lexer.h"

int		process_command_loop(t_parser *parser, t_env *envs)
{
  int		status;
  int		ex_status;
  t_parser	*save;

  ex_status = EXIT_SUCCESS;
  save = fork_loop(parser, &ex_status, envs);
  parser = save;
  while (save != NULL)
    {
      if (save->command->pid != -1 && save->command->is_builtin == 0)
	{
	  if (waitpid(save->command->pid, &status, 0) == -1)
	    return (-1);
	  if (WIFEXITED(status))
	    ex_status = status;
	  if (((save->son && save->son->command->pipefd[1] != -1) &&
	       close(save->son->command->pipefd[1]) == -1) ||
	      ((save->son && save->son->command->pipefd[0] != -1) &&
	       close(save->son->command->pipefd[0]) == -1))
	    return (get_error("Close error in process_command_loop"));
	}
      save = save->son;
    }
  free_parser(parser);
  return (0);
}

int		open_pipes(t_parser *parser)
{
  t_parser	*tmp;

  tmp = parser;
  while (tmp)
    {
      if (strcmp(tmp->data, "|") == 0
	  && pipe(tmp->command->pipefd) == -1)
	return (-1);
      tmp = tmp->father;
    }
  return (1);
}

void		get_allowed(t_parser *tmp, char *allowed, int *ex_status)
{
  *allowed = 1;
  if (strcmp(tmp->data, "&&") == 0 &&
      *ex_status == EXIT_FAILURE)
    *allowed = 0;
  if (strcmp(tmp->data, "||") == 0 &&
      *ex_status == EXIT_SUCCESS)
    *allowed = 0;
}

t_parser	*fork_loop(t_parser *parser, int *ex_status, t_env *envs)
{
  char		allowed;
  t_parser	*tmp;
  t_parser	*save;
  char		redir;

  tmp = parser;
  save = NULL;
  redir = 0;
  if (open_pipes(parser) < 0)
    return (NULL);
  while (tmp != NULL)
    {
      if (strcmp(tmp->data, "|") == 0 && (redir & RIGHT))
	redir = SON_RIGHT;
      else
	redir = 0;
      get_allowed(tmp, &allowed, ex_status);
      if (allowed == 1 &&
	  process_command_line(&tmp, envs, ex_status, &redir) == -1)
	return (NULL);
      if (tmp->father == NULL)
      	save = tmp;
      tmp = tmp->father;
    }
  return (save);
}
