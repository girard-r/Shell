/*
** check_type.c for 42sh in /home/vadee_s/rendu/42sh/lexer
** 
** Made by vadee
** Login   <vadee_s@epitech.net>
** 
** Started on  Wed Apr 23 23:32:00 2014 vadee
** Last update Sun Jun  1 17:34:56 2014 jolivald
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "lexer.h"

t_liste		*parse_entry(t_liste *list, char **cmd, int *j)
{
  int		k;

  if (is_token(cmd[*j]) == 0
      || is_separator(cmd[*j]) == 0)
    return (list);
  k = -1;
  while (cmd[*j][++k] != 0)
    {
      list = check_if_token(list, cmd, *j, &k);
      list = check_if_separator(list, cmd, *j, &k);
      if (cmd[*j][k] == 0)
	return (list);
    }
  return (list);
}

char            *path_command(char *command, char *path)
{
  char          *tmp;

  tmp = malloc((strlen(command) + strlen(path) + 2) * sizeof(char));
  if (tmp == NULL)
    return (NULL);
  strcpy(tmp, path);
  tmp[strlen(path)] = '/';
  tmp[strlen(path) + 1] = '\0';
  strcat(tmp, command);
  return (tmp);
}

int		path_exe(char *str)
{
  char		*tmp;

  if (strncmp(str, "/", 1) == 0)
    {
      if (access((tmp = path_command(str + 1, "")), X_OK) == 0)
	return (0);
    }
  else if (strncmp(str, "./", 1) == 0)
    {
      if (access((tmp = path_command(str + 2, ".")), X_OK) == 0)
	return (0);
    }
  else if (strncmp(str, "../", 1) == 0)
    {
      if (access((tmp = path_command(str + 3, "..")), X_OK) == 0)
	return (0);
    }
  return (1);
}

int		is_cmd(char *str, char **path)
{
  int		i;
  char		*tmp;

  i = 0;
  if (!path)
    return (0);
  if (path_exe(str) == 0)
    return (0);
  else
    {
      while (path[i] != NULL)
	{
	  if (access((tmp = path_command(str, path[i])), X_OK) == 0)
	    return (0);
	  i = i + 1;
	  free(tmp);
	}
    }
  return (1);
}
