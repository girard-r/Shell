/*
** process_error.c for 42sh in /home/vadee_s/rendu/42sh/42sh/lexer
** 
** Made by vadee
** Login   <vadee_s@epitech.net>
** 
** Started on  Tue May  6 17:03:31 2014 vadee
** Last update Sat May 24 13:00:23 2014 vadee
*/

#include <stdio.h>
#include <stdlib.h>
#include "lexer.h"

void		find_opposite(char *sep, char *op)
{
  if (*sep == '(')
    *op = ')';
  else if (*sep == '{')
    *op = '}';
}

int		check_separator(t_liste *list)
{
  t_liste	*tmp;
  char		sep;
  char		opposite;
  int		count_sep;
  int		count_op;

  count_sep = 0;
  count_op = 0;
  sep = list->data[0];
  find_opposite(&sep, &opposite);
  tmp = list;
  while (tmp != NULL)
    {
      if (tmp->data[0] == sep)
	count_sep += 1;
      if (tmp->data[0] == opposite)
	if (++count_op > count_sep)
	  return (-1);
      tmp = tmp->next;
    }
  if (count_sep != count_op)
    return (-1);
  return (0);
}

int		process_error(t_liste *list)
{
  t_liste	*tmp;

  tmp = list;
  if (count_tokens(tmp) == -1)
    {
      my_putstr("\nMismatched token !");
      return (-1);
    }
  while (tmp != NULL)
    {
      if ((tmp->data[0] == '('
	   || tmp->data[0] == '{')
	  && check_separator(tmp) == -1)
	{
	  printf("mismatched parenthesis or curly braces !\n");
	  return (-1);
	}
      tmp = tmp->next;
    }
  return (0);
}
