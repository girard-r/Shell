/*
** parse_builtins.c for 42sh in /home/vadee_s/rendu/42sh/42sh/lexer
** 
** Made by vadee
** Login   <vadee_s@epitech.net>
** 
** Started on  Mon May  5 19:37:08 2014 vadee
** Last update Sun Jun  1 18:07:36 2014 jolivald
*/

#include <string.h>
#include <stdlib.h>
#include "lexer.h"

static const char	*builtins[10] =
  {
    "cd",
    "setenv",
    "unsetenv",
    "env",
    "exit",
    "echo",
    "history",
    NULL,
  };

int			is_builtin(char *str)
{
  int			i;
  i = 0;
  while (builtins[i] != NULL)
    {
      if (strcmp(str, builtins[i++]) == 0)
	return (0);
    }
  return (1);
}
