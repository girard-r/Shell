/*
** b_env.c for mysh in /home/joliva_d/rendu/Unix/MSH1
** 
** Made by jolivald
** Login   <joliva_d@epitech.net>
** 
** Started on  Thu Dec 12 19:54:25 2013 jolivald
** Last update Sun Jun  1 18:06:06 2014 jolivald
*/

#include <stdlib.h>
#include "trunc.h"

char	**do_b_env(char **entry, char **env, int *status)
{
  int	i;
  char	**tmp;

  tmp = entry;
  tmp += 1;
  i = -1;
  *status = EXIT_SUCCESS;
  while (env[++i])
    {
      if (env[i][0] != 0)
	{
	  my_putstr(env[i]);
	  my_putstr("\n");
	}
    }
  return (env);
}
