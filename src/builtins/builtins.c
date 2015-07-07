/*
** builtins.c for builtins in /home/girard_r/Documents/PSU_2013_minishell1
** 
** Made by girard_r
** Login   <girard_r@epitech.net>
** 
** Started on  Mon Dec 16 17:43:10 2013 girard_r
** Last update Sun Jun  1 17:57:12 2014 jolivald
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "builtin.h"
#include "trunc.h"

int	change_pwd(char **envp, char *filename)
{
  int	i;
  char	*str;
  int	max;

  i = 0;
  if (envp == NULL)
    return (-1);
  while (envp[i] && strncmp(envp[i], "PWD=", 4) != 0)
    i += 1;
  if (envp[i] == NULL)
    return (-1);
  max = strlen(envp[i]);
  if ((str = malloc(sizeof(char) * (max + strlen(filename) + 2))) == NULL)
    return (-1);
  if (filename[0] != '.' && filename[0] != '/')
    {
      strcpy(str, envp[i]);
      str[max] = '/';
      str[max + 1] = 0;
      strcat(str, filename);
      free(envp[i]);
      envp[i] = str;
    }
  return (0);
}

char	**builtin_cd(char **new_av, char **envp, int *ret)
{
  int	i;
  char	*home;

  i = -1;
  envp = check_if_oldpath(envp, ret);
  if ((home = get_home(envp)) == NULL)
    {
      *ret = 1;
      return (envp);
    }
  while (new_av[++i]);
  if (i == 1)
    envp = check_for_access_cd(home, 0, envp, ret);
  else
    envp = check_for_access_cd(new_av[1], 1, envp, ret);
  if (home != NULL)
    free(home);
  return (envp);
}
