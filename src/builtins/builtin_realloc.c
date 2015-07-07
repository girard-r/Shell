/*
** builtin_realloc.c for 42sh in /home/joliva_d/rendu/42sh/src/builtins/usefull
** 
** Made by jolivald
** Login   <joliva_d@epitech.net>
** 
** Started on  Sun Jun  1 13:39:54 2014 jolivald
** Last update Sun Jun  1 18:04:11 2014 jolivald
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdlib.h>
#include "builtin.h"

int	b_tab_len(char **b_tab)
{
  int	i;

  i = 0;
  while (b_tab && b_tab[i])
    i += 1;
  return (i);
}

char	**my_realloc_env(char **envp, char *name, char *value, int *ret)
{
  int	len_envp;
  char	**new_envp;
  int	i;

  i = -1;
  *ret = 1;
  len_envp = b_tab_len(envp);
  if ((new_envp = malloc(sizeof(char *) * (len_envp + 2))) == NULL)
    return (envp);
  if (envp != NULL)
    {
      while (envp[++i])
        new_envp[i] = strdup(envp[i]);
    }
  if ((new_envp[i] = malloc(sizeof(char) *
			    (strlen(name) + strlen(value) + 2))) == NULL)
    return (envp);
  strcpy(new_envp[i], name);
  strcat(new_envp[i], "=");
  strcat(new_envp[i++], value);
  new_envp[i] = NULL;
  if (envp != NULL)
    b_free_tab(envp);
  *ret = 0;
  return (new_envp);
}

char	**my_realloc_less(char **envp, int pos, int *ret)
{
  int	len_envp;
  char	**new_envp;
  int	i;
  int	j;

  i = 0;
  j = 0;
  len_envp = b_tab_len(envp);
  if ((new_envp = malloc(sizeof(char *) * len_envp)) == NULL)
    {
      *ret = 1;
      return (envp);
    }
  while (envp[i])
    {
      if (i == pos)
        i = i + 1;
      if (envp[i])
        new_envp[j++] = strdup(envp[i++]);
    }
  new_envp[j] = NULL;
  b_free_tab(envp);
  return (new_envp);
}

char	**back_path(char **env)
{
  int	i;
  int	j;
  char	*tmp;
  char	**old;
  char	**new;

  i = 0;
  j = 0;
  while (env[i] && strncmp(env[i], "PWD=", 4) != 0)
    i += 1;
  while (env[j] && strncmp(env[j], "OLDPWD=", 7) != 0)
    j += 1;
  if (env[i] == NULL || env[j] == NULL)
    return (env);
  new = my_str_to_wordtab2(env[i]);
  old = my_str_to_wordtab2(env[j]);
  tmp = new[1];
  new[1] = old[1];
  old[1] = tmp;
  return (env);
}

char	**check_for_access_cd(char *filename, int flag, char **envp, int *ret)
{
  if (strcmp(filename, "-") == 0)
    {
      return (back_path(envp));
    }
  if (access(filename, F_OK) == -1)
    {
      if (flag == 0)
        printf("cd: HOME not set\n");
      else
        printf("cd: %s: No such file or directory\n", filename);
      return (envp);
    }
  if (access(filename, X_OK) == -1)
    {
      printf("cd: %s: Permission denied\n", filename);
      return (envp);
    }
  if (chdir(filename) == -1)
    return (envp);
  if (change_pwd(envp, filename) == -1)
    *ret = 1;
  return (envp);
}
