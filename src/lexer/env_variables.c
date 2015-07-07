/*
** env_variables.c for 42sh in /home/vadee_s/rendu/42sh/42sh/lexer
** 
** Made by vadee
** Login   <vadee_s@epitech.net>
** 
** Started on  Wed May  7 13:51:44 2014 vadee
** Last update Wed May  7 14:21:04 2014 vadee
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lexer.h"

t_liste		*replace_env_variable(t_liste *tmp, char **env)
{
  int		i;

  i = -1;
  tmp->data += 1;
  while (env[++i] != NULL)
    {
      if (strncmp(tmp->data, env[i], strlen(tmp->data)) == 0)
	{
	  if ((tmp->data = strdup(env[i] + strlen(tmp->data)) + 1) == NULL)
	    return (NULL);
	  return (tmp);
	}
      else if (env [i + 1] == NULL)
	{
	  printf("Variable %c%s not found !\n", '$', tmp->data);
	  return (NULL);
	}
    }
  return (tmp);
}

t_liste		*find_env_variables(t_liste *list, char **env)
{
  t_liste	*tmp;

  tmp = list;
  while (tmp != NULL)
    {
      if (tmp->data[0] == '$')
	{
	  if ((tmp = replace_env_variable(tmp, env)) == NULL)
	    return (NULL);
	}
      tmp = tmp->next;
    }
  return (list);
}
