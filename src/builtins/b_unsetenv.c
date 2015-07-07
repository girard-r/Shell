/*
** b_unsetenv.c for mysh in /home/joliva_d/rendu/Unix/MSH1/builtins
** 
** Made by jolivald
** Login   <joliva_d@epitech.net>
** 
** Started on  Mon Dec 16 14:23:46 2013 jolivald
** Last update Sun Jun  1 17:20:55 2014 jolivald
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "trunc.h"
#include "builtin.h"

char	**do_b_unsetenv(char **entry, char **env, int *status)
{
  int	i;

  *status = EXIT_SUCCESS;
  i = 0;
  while (entry[i] != NULL)
    i++;
  if (i == 1)
    my_putstr("Unetenv usage : unsetenv [NAME]\n");
  else
    env = second_part_unsetenv(env, entry, status);
  return (env);
}

char	**second_part_unsetenv(char **env, char **params, int *status)
{
  int	i;
  int	len;

  i = 0;
  len = strlen(params[1]);
  while (env[i] != NULL && my_strequalncmp(env[i], params[1], len) != 0)
    i += 1;
  if (env[i] == NULL)
    {
      my_putstr("Error : invalid argument for unsetenv builtin\n");
      my_putstr("Unetenv usage : unsetenv [NAME]\n");
      *status = EXIT_FAILURE;
      return (env);
    }
  env[i][0] = '\0';
  return (env);
}

int	my_strequalncmp(char *str1, char *str2, int n)
{
  int	i;

  i = 0;
  while (str1[i] == str2[i] && i < n)
    i++;
  if (i == n && str1[i] == '=')
    return (0);
  return (1);
}
