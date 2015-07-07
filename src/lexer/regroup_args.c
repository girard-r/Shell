/*
** regroup_args.c for 42sh in /home/vadee_s/rendu/42sh/lexer
** 
** Made by vadee_s
** Login   <vadee_s@epitech.net>
** 
** Started on  Sat May 10 17:55:10 2014 vadee_s
** Last update Wed May 21 11:16:16 2014 vadee
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lexer.h"

t_liste		*fill_args_list(t_liste *list)
{
  t_liste	*tmp;
  int		i;

  i = 0;
  list->data[0] = 0;
  tmp = list->next;
  while (tmp != NULL && tmp->data[0] != '"')
    {
      if ((list->data = realloc(list->data, strlen(list->data)
				+ strlen(tmp->data) + 2)) == NULL)
	return (NULL);
      if (i++ != 0)
	strcat(list->data, " ");
      strcat(list->data, tmp->data);
      if (tmp->next != NULL && (tmp = tmp->next) != NULL)
	suppr_elem_list(tmp->prev);
    }
  if (tmp != NULL && tmp->data[0] == '"')
    {
      tmp = tmp->prev;
      suppr_elem_list(tmp->next);
    }
  while (tmp != NULL)
    tmp = tmp->prev;
  return (list);
}

t_liste		*regroup_args(t_liste *list)
{
  t_liste	*tmp;
  int		count;

  count = 0;
  tmp = list;
  while (tmp != NULL)
    {
      if (tmp->data[0] == '"'
	  && count % 2 == 0)
	{
	  count += 1;
	  fill_args_list(tmp);
	  tmp->type = OTHER;
	}
      if (tmp != NULL)
	tmp = tmp->next;
    }
  return (list);
}
