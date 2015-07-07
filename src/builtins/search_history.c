/*
** search_history.c for 42sh in /home/joliva_d/rendu/42sh/src/builtins
** 
** Made by jolivald
** Login   <joliva_d@epitech.net>
** 
** Started on  Sun Jun  1 13:10:48 2014 jolivald
** Last update Sun Jun  1 18:01:20 2014 jolivald
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "builtin.h"

static char	**add_in_tab(char *str, char **history)
{
  char		**buffer;
  int		i;

  i = 0;
  if (history == NULL)
    {
      if ((buffer = malloc(sizeof(char*) * 2)) == NULL)
	return (NULL);
      buffer[0] = strdup(str);
      buffer[1] = NULL;
    }
  else
    {
      while (history[i++] != NULL);
      if ((buffer = malloc(sizeof(char*) * (i + 2))) == NULL)
      	return (NULL);
      i = -1;
      while (history[++i] != NULL)
      	buffer[i] = strdup(history[i]);
      buffer[i++] = strdup(str);
      buffer[i] = NULL;
    }
  return (buffer);
}

char	*search_cmd(char **history, int pos)
{
  int	i;

  i = -1;
  while (history[++i] != NULL);
  if (i - pos < 0)
    return (NULL);
  else
    return (history[i - pos] + 2);
}

char	*search_history(int pos)
{
  int	fd;
  char	**history;
  char	*buffer;
  char	*cmd;

  history = NULL;
  if ((fd = open("/tmp/.42shistory", O_RDONLY)) == -1)
    {
      perror("Open error");
      return (NULL);
    }
  while ((buffer = get_next_line(fd)) != NULL && buffer[0] != 0)
    {
      if ((history = add_in_tab(buffer, history)) == NULL)
         return (NULL);
    }
  if (history != NULL)
    cmd = search_cmd(history, pos);
  return (cmd);
}
