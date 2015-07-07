/*
** funcs_2_setenv.c for mysh in /home/joliva_d/rendu/Unix/MSH1
** 
** Made by jolivald
** Login   <joliva_d@epitech.net>
** 
** Started on  Fri Dec 13 17:21:05 2013 jolivald
** Last update Sun Jun  1 16:52:02 2014 jolivald
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "builtin.h"

char	**do_setenv(char **env, char *value, char *name, int *status)
{
  char	**cpy;
  int	i;

  i = 0;
  while (env[i] != NULL)
    i++;
  if ((cpy = dispatch_setenv(env, value, name, &i)) == NULL)
    {
      perror("Abort : malloc error\n");
      *status = EXIT_FAILURE;
      return (env);
    }
  cpy[i + 1] = NULL;
  free_env(env);
  return (cpy);
}

char	**dispatch_setenv(char **env, char *value, char *name, int *i)
{
  char	**cpy;

  if ((cpy = malloc((*i + 2) * sizeof(char*))) == NULL)
    return (NULL);
  *i = 0;
  while (env[*i] != NULL)
    {
      if (env[*i] != NULL)
	if ((cpy[*i] = strdup(env[*i])) == NULL)
	  {
	    perror("Abort : strdup error");
	    return (NULL);
	  }
      *i += 1;
    }
  if ((cpy[*i] = get_env(name, value)) == NULL)
      return (NULL);
  return (cpy);
}
