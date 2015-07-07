/*
** parse_separators.c for 42sh in /home/vadee_s/rendu/42sh/42sh/lexer
** 
** Made by vadee
** Login   <vadee_s@epitech.net>
** 
** Started on  Mon May  5 19:35:08 2014 vadee
** Last update Sat May 24 18:28:47 2014 vadee
*/

#include <string.h>
#include <stdlib.h>
#include "lexer.h"

static const char	*separators[7] =
  {
    "`",
    "'",
    "{",
    "}",
    "(",
    ")",
    NULL,
  };

t_liste		*check_if_separator(t_liste *list, char **cmd, int j, int *k)
{
  int		i;

  i = -1;
  while (separators[++i] != NULL)
    {
      if (cmd[j][*k] == separators[i][0] || cmd[j][*k] == '"')
	{
          if (*k != 0
	      && (list = add_elem_in_list(list, cmd[j], *k)) == NULL)
	    return (NULL);
	  cmd[j] += *k;
	  if ((list = add_elem_in_list(list, cmd[j], 1)) == NULL)
	    return (NULL);
	  if (cmd[j][0] != 0)
	    cmd[j] += 1;
	  *k = 0;
	}
    }
  return (list);
}

int			is_separator(char *str)
{
  int			i;
  char			c;

  c = '"';
  i = 0;
  while (separators[i] != NULL)
    {
      if (strcmp(str, &c) == 0)
	return (0);
      if (strcmp(str, separators[i++]) == 0)
	return (0);
    }
  return (1);
}
