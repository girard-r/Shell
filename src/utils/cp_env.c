/*
** cp_env.c for cp_env in /home/vadee_s/rendu/42sh/42sh
** 
** Made by vadee
** Login   <vadee_s@epitech.net>
** 
** Started on  Wed Apr 23 23:07:33 2014 vadee
** Last update Sat May 24 18:42:06 2014 girard_r
*/

#include <string.h>
#include <stdlib.h>

char		**cp_env(char **envp, int j)
{
  char		**env;
  int		i;

  i = 0;
  while (envp[i] != NULL)
    i++;
  if ((env = malloc(sizeof(char*) * (i + 1 + j))) == NULL)
    return (NULL);
  i = -1;
  while (envp[++i] != NULL)
    env[i] = strdup(envp[i]);
  env[i] = NULL;
  if (j == 1)
    {
      i = 0;
      while (envp[i] != NULL)
	free(envp[i++]);
      free(envp);
    }
  return (env);
}
