/*
** test.c for 42sh in /home/joliva_d/rendu/42sh/src/parser
** 
** Made by jolivald
** Login   <joliva_d@epitech.net>
** 
** Started on  Sun Jun  1 18:24:39 2014 jolivald
** Last update Sun Jun  1 22:03:18 2014 jolivald
*/

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include "parser.h"

int		test_pipe(t_parser *parser, char redir)
{
  if (!(redir & RIGHT) &&(parser->son) &&
      strcmp(parser->son->data, "|") == 0 &&
      (close(parser->son->command->pipefd[0]) == -1 ||
       (!(redir & SON_RIGHT) &&dup2(parser->son->command->pipefd[1], 1) == -1)))
    {
      perror("Test_pipe RIGHT error");
      return (-1);
    }
  if (!(redir & LEFT) &&strcmp(parser->data, "|") == 0 &&
      (close(parser->command->pipefd[1]) == -1 ||
       dup2(parser->command->pipefd[0], 0) == -1))
    {
      perror("Test_pipe LEFT error");
      return (-1);
    }
  return (0);
}

int		test_redir(t_parser **parser, char *redir)
{
  t_parser	*tmp;

  tmp = *parser;
  while (get_prio_op(tmp->data) == 3 && strcmp(tmp->data, "|") != 0)
    {
      if (parser && strcmp(tmp->data, ">") == 0 &&
	  (test_single_right(tmp, redir) < 0))
	return (-1);
      if (parser && strcmp(tmp->data, ">>") == 0 &&
	  (test_double_right(tmp, redir) < 0))
	return (-1);
      if (parser && strcmp(tmp->data, "<") == 0 &&
	  (test_single_left(tmp, redir) < 0))
	return (-1);
      if (parser && strcmp(tmp->data, "<<") == 0 &&
	  (test_double_left(tmp, redir) < 0))
	return (-1);
      tmp = tmp->father;
    }
  *parser = tmp;
  return (0);
}

