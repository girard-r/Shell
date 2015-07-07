/*
** test.c for 42sh in /home/ngo-va_a/rendu/42sh/builtins
** 
** Made by ngo-va_a
** Login   <ngo-va_a@epitech.net>
** 
** Started on  Sun May 25 15:49:58 2014 ngo-va_a
** Last update Sun Jun  1 17:31:22 2014 jolivald
*/

#include <stdlib.h>
#include <string.h>
#include "builtin.h"
#include "parser.h"

static const t_built	g_builtin[8] =
  {
    {"env", &do_b_env},
    {"setenv", &do_b_setenv},
    {"unsetenv", &do_b_unsetenv},
    {"exit", &b_exit},
    {"echo", &b_echo},
    {"cd", &builtin_cd},
    {"history", &b_history},
    {NULL, NULL}
  };

int	select_builtin(char **data, t_env *envs, int *status)
{
  int	i;

  i = 0;
  while (g_builtin[i].cmd != NULL)
    {
      if (strcmp(*data, g_builtin[i].cmd) == 0)
	{
	  envs->env = g_builtin[i].funcptr(data, envs->env, status);
	  return (0);
	}
      i += 1;
    }
  return (-1);
}
