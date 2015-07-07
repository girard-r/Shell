/*
** pars_path.c for 42sh in /home/vadee_s/rendu/42sh/42sh/lexer
** 
** Made by vadee
** Login   <vadee_s@epitech.net>
** 
** Started on  Mon May  5 14:20:05 2014 vadee
** Last update Thu May 29 13:11:09 2014 jolivald
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "lexer.h"

char		**parse_path(char **env)
{
  int		i;
  char		**path;

  i = 0;
  path = NULL;
  while (env[i] != NULL)
    {
      if (strncmp(env[i], "PATH=", 5) == 0)
	path = my_str_to_wordtab_path(env[i]);
      i++;
    }
  if (env[i] == NULL && path == NULL)
    {
      printf("\nPATH not set\n");
      return (NULL);
    }
  return (path);
}
