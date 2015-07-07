/*
** getenv.c for getenv in /home/girard_r/Documents/PSU_2013_minishell1
** 
** Made by girard_r
** Login   <girard_r@epitech.net>
** 
** Started on  Wed Dec 18 14:56:55 2013 girard_r
** Last update Sun Jun  1 18:05:45 2014 jolivald
*/

#include <stdlib.h>
#include <string.h>
#include "builtin.h"

char	*get_home(char **envp)
{
  int	i;
  int	j;
  char	*home;

  i = -1;
  j = 5;
  home = NULL;
  if (!envp)
    return (home);
  while (envp[++i] != NULL)
    {
      if (strncmp("HOME=", envp[i], 5) == 0)
	{
	  if ((home = malloc(sizeof(char) *
			     (strlen(envp[i]) - 4))) == NULL)
	    return (NULL);
	  while (envp[i][j])
	    {
	      home[j - 5] = envp[i][j];
	      j += 1;
	    }
	  home[j - 5] = 0;
	}
    }
  return (home);
}

char	**check_if_oldpath(char **envp, int *ret)
{
  int	i;
  int	j;
  char	**tmp;

  i = 0;
  j = 0;
  *ret = 1;
  while (envp[i] && strncmp(envp[i], "OLDPWD=", 7) != 0)
    i += 1;
  while (envp[j] && strncmp(envp[j], "HOME=", 5) != 0)
    j += 1;
  if (envp[i] == NULL || envp[j] == NULL)
    {
      if ((tmp = my_str_to_wordtab2(envp[j])) == NULL)
	return (envp);
      my_change_env(envp, "OLDPWD", tmp[1], ret);
    }
  *ret = 0;
  return (envp);
}

int	test_exists(char **envp, char *name)
{
  int	i;

  i = 0;
  while (envp[i])
    {
      if (strncmp(envp[i], name, strlen(name)) == 0)
	return (i);
      i += 1;
    }
  return (-1);
}

char	**my_change_env(char **envp, char *name, char *value, int *ret)
{
  int	pos;

  *ret = 1;
  if ((pos = test_exists(envp, name)) == -1)
    envp = my_realloc_env(envp, name, value, ret);
  else
    {
      free(envp[pos]);
      if ((envp[pos] = malloc(sizeof(char) *
			      (strlen(name) + strlen(value) + 2))) == NULL)
	return (NULL);
      *ret = 0;
      strcpy(envp[pos], name);
      strcat(envp[pos], "=");
      strcat(envp[pos], value);
    }
  return (envp);
}
