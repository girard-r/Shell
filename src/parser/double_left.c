/*
** double_left.c for 42sh in /home/joliva_d/rendu/42sh/src/parser
** 
** Made by jolivald
** Login   <joliva_d@epitech.net>
** 
** Started on  Sun Jun  1 18:18:01 2014 jolivald
** Last update Sun Jun  1 19:13:32 2014 jolivald
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

int		test_double_left(t_parser *parser, char *redir)
{
  int		tmpipe[2];
  t_parser	*cmdp;

  if (!(*redir & LEFT))
    {
      if (pipe(tmpipe) == -1)
	return (get_error("Pipe error in test_double_left"));
      cmdp = get_parent_cmd(parser);
      if (process_double_left(redir, parser, tmpipe, cmdp) != 1)
	return (-1);
      if (dup2(cmdp->command->pipefd[0], 0) == -1)
	return (get_error("dup2 error in test_double_left"));
    }
  return (1);
}

int		process_double_left(char *redir, t_parser *parser,
				    int *tmpipe, t_parser *cmdp)
{
  char			*s;
  struct termios	term;

  if (tcgetattr(0, &term) == -1)
    return (get_error("tcgetattr Error in test_double_left"));
  while (!(*redir & LEFT) && (s = get_command_line(0, &term)))
    {
      if (strcmp(s, parser->command->new_argv[0]) == 0)
	{
	  close(tmpipe[1]);
	  cmdp->command->pipefd[0] = tmpipe[0];
	  *redir |= LEFT;
	}
      else
	{
	  write(tmpipe[1], s, my_strlen(s));
	  write(tmpipe[1], "\n", 1);
	}
      write(1, "\n", 1);
      free(s);
    }
  return (1);
}
