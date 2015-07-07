/*
** parse_tokens.c for 42sh in /home/joliva_d/rendu/42sh/lexer
** 
** Made by jolivald
** Login   <joliva_d@epitech.net>
** 
** Started on  Tue May 27 21:06:21 2014 jolivald
** Last update Sun Jun  1 18:10:28 2014 jolivald
*/

#include <string.h>
#include <stdlib.h>
#include "lexer.h"

static const char	*tokens[13] =
  {
    ">>",
    "<<",
    ">!",
    "!<",
    "<",
    ">",
    "||",
    "|",
    "&&",
    "&",
    ";",
    "&!",
    NULL,
  };

t_liste		*check_if_token(t_liste *list, char **cmd, int j, int *k)
{
  int		i;

  i = -1;
  while (tokens[++i] != NULL)
    {
      if (cmd[j][*k] == tokens[i][0])
	{
	  if (*k != 0 && (list = add_elem_in_list(list, cmd[j], *k)) == NULL)
	    return (NULL);
	  cmd[j] += *k;
	  *k = 0;
	  if (cmd[j][*k] != 0 && cmd[j][*k + 1] == tokens[i][1])
	    {
	      if ((list = add_elem_in_list(list, cmd[j], 2)) == NULL)
		return (NULL);
              cmd[j] += 1;
	    }
	  else if ((list = add_elem_in_list(list, cmd[j], 1)) == NULL)
	    return (NULL);
	  cmd[j] += 1;
	  i = -1;
        }
    }
  return (list);
}

int			is_token(char *str)
{
  int			i;

  i = 0;
  while (tokens[i] != NULL)
    {
      if (strcmp(str, tokens[i++]) == 0)
	return (0);
    }
  return (1);
}
