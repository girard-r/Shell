/*
** init_and_pars.c for miinishell init in /home/vadee_s/rendu/PSU_2013_minishell1
** 
** Made by vadee
** Login   <vadee_s@epitech.net>
** 
** Started on  Wed Dec 11 11:00:43 2013 vadee
** Last update Sun May 25 01:47:33 2014 girard_r
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../trunc.h"

int		set_prompt(char *env[])
{
  int		i;
  int		j;
 
  j = 0;
  i = 0;
  while ((env[i] != NULL) && (strncmp(env[i], "HOSTNAME", 8) != 0))
    i = i + 1;
  while ((env[j] != NULL) && (strncmp(env[j], "USER", 4) != 0))
    j = j + 1;
  if (env[i] != NULL && env[j] != NULL)
    {
      //      my_putchar('\n');
      my_putstr(env[j] + 5);
      my_putchar('@');
      my_putstr(env[i] + 9);
      my_putstr("> ");
    }
  else
    {
      my_putstr("\nwhat_is@your_name$> ");
    }
  return (0);
}

void		my_free_path(char **path)
{
  int		i;

  i = 0;
  while (path[i] != NULL)
    free(path[i++]);
  free(path);
}
