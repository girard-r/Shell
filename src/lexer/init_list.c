/*
** init_list.c for 42sh in /home/vadee_s/rendu/42sh/lexer
** 
** Made by vadee
** Login   <vadee_s@epitech.net>
** 
** Started on  Wed Apr 23 21:52:57 2014 vadee
** Last update Sun Jun  1 18:07:50 2014 jolivald
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lexer.h"

int		fill_data_list(t_liste *new, char *str, int ndup)
{
  char		*tmp;

  tmp = str;
  if (ndup > 0)
    {
      if ((new->data = strndup(str, ndup)) == NULL)
	return (-1);
    }
  else if (ndup < 0)
    {
      tmp = tmp + (strlen(tmp) - (-ndup));
      if ((new->data = strdup(tmp)) == NULL)
	return (-1);
    }
  else
    new->data = str;
  return (0);
}

t_liste		*add_elem_in_list(t_liste *racine, char *str, int ndup)
{
  t_liste	*new;
  t_liste	*tmp;

  if ((new = malloc(sizeof(t_liste))) == NULL
      || fill_data_list(new, str, ndup) == -1)
    return (NULL);
  new->next = NULL;
  if (racine == NULL)
    {
      new->prev = NULL;
      return (new);
    }
  else
    {
      tmp = racine;
      while (tmp->next != NULL)
	tmp = tmp->next;
      tmp->next = new;
      new->prev = tmp;
      return (racine);
    }
}

t_liste		*linked_list(char **cmd)
{
  int		i;
  t_liste       *list;

  i = 0;
  list = NULL;
  while (cmd[i] != NULL)
    {
      list = parse_entry(list, cmd, &i);
      if (cmd[i][0] != 0
	  && (list = add_elem_in_list(list, cmd[i], 0)) == NULL)
	return (NULL);
      i += 1;
    }
  return (list);
}
