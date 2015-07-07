/*
** redir.c for 42 in /home/joliva_d/rendu/42sh
** 
** Made by jolivald
** Login   <joliva_d@epitech.net>
** 
** Started on  Sat May 31 16:22:40 2014 jolivald
** Last update Sun Jun  1 21:30:25 2014 jolivald
*/

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <unistd.h>
#include "parser.h"
#include "trunc.h"

t_parser	*get_parent_cmd(t_parser *current)
{
  t_parser	*tmp;

  tmp = current;
  while (strcmp(tmp->data, "|") != 0 &&
	 strcmp(tmp->data, "START") != 0 &&
	 strcmp(tmp->data, "||") != 0 &&
	 strcmp(tmp->data, "&&") != 0 &&
	 strcmp(tmp->data, ";") != 0)
    tmp = tmp->father;
  return (tmp);
}

int		test_single_right(t_parser *parser, char *redir)
{
  int		fd;
  t_parser	*cmdp;

  if (*redir & RIGHT &&
      ((fd = open(parser->command->new_argv[0], O_CREAT | O_TRUNC,
		  S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH) == -1) ||
       (close(fd) == -1)))
    return (get_error("test_single_right error"));
  else if (!(*redir & RIGHT))
    {
      cmdp = get_parent_cmd(parser);
      if ((cmdp->command->pipefd[1] != -1 &&
	   close(cmdp->command->pipefd[1]) == -1))
	return (get_error("test_single_right error"));
      if ((fd = open(parser->command->new_argv[0],
		     O_WRONLY | O_CREAT | O_TRUNC,
		     S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
	return (get_error("test_single_right error"));
      cmdp->command->pipefd[1] = fd;
      *redir = *redir | RIGHT;
      if (dup2(cmdp->command->pipefd[1], 1) == -1)
      	return (get_error("dup2 error in test_single_right"));
    }
  return (1);
}

int		test_double_right(t_parser *parser, char *redir)
{
  int		fd;
  t_parser	*cmdp;

  if (*redir & RIGHT &&
      ((fd = open(parser->command->new_argv[0], O_CREAT,
		  S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH) == -1) ||
       (close(fd) == -1)))
    return (get_error("test_double_right error"));
  else if (!(*redir & RIGHT))
    {
      cmdp = get_parent_cmd(parser);
      if (cmdp->command->pipefd[1] != -1 &&
	  close(cmdp->command->pipefd[1]) == -1)
	return (get_error("test_double_right error"));
      if ((fd = open(parser->command->new_argv[0],
		     O_WRONLY | O_CREAT | O_APPEND,
		     S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
	return (get_error("test_double_right error"));
      cmdp->command->pipefd[1] = fd;
      *redir = *redir | RIGHT;
      if (dup2(cmdp->command->pipefd[1], 1) == -1)
	return (get_error("dup2 error in test_double_right"));
    }
  return (1);
}

int		test_single_left(t_parser *parser, char *redir)
{
  int		fd;
  t_parser	*cmdp;

  if (!(*redir & LEFT))
    {
      cmdp = get_parent_cmd(parser);
      if (cmdp->command->pipefd[0] != -1 &&
	  close(cmdp->command->pipefd[0]) == -1)
	return (get_error("test_single_left error"));
      if ((fd = open(parser->command->new_argv[0], O_RDONLY)) == -1)
	return (get_error("test_single_left error"));
      cmdp->command->pipefd[0] = fd;
      *redir = *redir | LEFT;
      if (dup2(cmdp->command->pipefd[0], 0) == -1)
	return (get_error("dup2 error in test_single_left"));
    }
  return (1);
}

int		get_error(const char *str)
{
  perror(str);
  return (-1);
}
