/*
** b_setenv.c for mysh in /home/joliva_d/rendu/Unix/MSH1/builtins
** 
** Made by jolivald
** Login   <joliva_d@epitech.net>
** 
** Started on  Thu Dec 12 20:02:10 2013 jolivald
** Last update Sun Jun  1 16:59:53 2014 jolivald
*/

#include <stdlib.h>
#include <string.h>
#include "trunc.h"
#include "builtin.h"

char	**do_b_setenv(char **entry, char **env, int *status)
{
  int	exist;
  int	i;

  i = 0;
  *status = EXIT_SUCCESS;
  while (entry[i] != NULL)
    i++;
  if (i != 4)
    {
      my_putstr("Error : invalid argument for setenv builtin\n");
      my_putstr("Setenv usage : setenv [NAME] [VALUE] [OVERWRITE : 0/1]\n");
      return (env);
    }
  exist = is_env_exist(entry[1], env);
  if (exist != 0 && strcmp(entry[3], "1") == 0)
    env[exist] = do_setenv_overwrite(env[exist], entry[2], entry[1], status);
  else if (exist == 0)
    env = do_setenv(env, entry[2], entry[1], status);
  else
    my_putstr("Setenv usage : setenv [NAME] [VALUE] [OVERWRITE : 0/1]\n");
  i = 0;
  return (env);
}

