/*
** funcs_setenv.c for mysh in /home/joliva_d/rendu/Unix/MSH1
** 
** Made by jolivald
** Login   <joliva_d@epitech.net>
** 
** Started on  Fri Dec 13 16:11:37 2013 jolivald
** Last update Sun Jun  1 18:04:30 2014 jolivald
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "builtin.h"

char	*do_setenv_overwrite(char *env, char *value, char *name, int *status)
{
  free(env);
  env = get_env(name, value);
  if (env == NULL)
    {
      perror("Malloc error, environement is corrupt\n");
      *status = EXIT_FAILURE;
    }
  return (env);
}

int	is_env_exist(char *param, char **env)
{
  int	len;
  int	i;

  i = 0;
  len = strlen(param) - 1;
  while (env[i] != NULL)
    {
      if ((strncmp(env[i], param, len)) == 0 && env[i][len + 1] == '=')
	return (i);
      i++;
    }
  return (0);
}

char	*get_env(char *name, char *value)
{
  char	*env;
  int	len;
  int	i;

  i = 0;
  len = strlen(value) + strlen(name) + 2;
  if ((env = malloc(len * sizeof(char))) == NULL)
    return (NULL);
  while (*name)
    {
      env[i] = *name;
      i += 1;
      name += 1;
    }
  env[i++] = '=';
  while (*value)
    {
      env[i] = *value;
      i += 1;
      value += 1;
    }
  env[i] = 0;
  return (env);
}

void	free_env(char **env)
{
  int	i;

  i = -1;
  while (env[++i] != NULL)
    free(env[i]);
  free(env);
}
