/*
** order_types.c for 42sh in /home/vadee_s/rendu/42sh/lexer
** 
** Made by vadee
** Login   <vadee_s@epitech.net>
** 
** Started on  Sat May 24 13:02:08 2014 vadee
** Last update Sat May 31 23:09:33 2014 jolivald
*/

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "lexer.h"

int			if_token(t_liste *tmp)
{
  if (tmp->next != NULL && strcmp(tmp->data, "<") == 0
      && access(tmp->next->data, F_OK | R_OK) == -1)
    {
      printf("Cannot acces to %s !\n", tmp->next->data);
      return (-1);
    }
  if ((tmp->next == NULL && tmp->prev == NULL)
      || ((tmp->prev == NULL || tmp->prev->data[0] == ';')
	  && (tmp->data[0] != '>' && tmp->data[0] != '<')))
    return (-1);
  if (tmp->prev != NULL && tmp->prev->type == TOKEN)
    {
      if (tmp->data[0] == '|'
	  || strcmp(tmp->data, tmp->prev->data) == 0)
	return (-1);
      else if ((tmp->data[0] == '&' || tmp->data[0] == '|')
	       && (tmp->prev->data[0] == '&' || tmp->prev->data[0] == '|'))
	return (-1);
    }
  else if (tmp->prev != NULL && tmp->prev->type == SEPARATOR)
    {
      if (!(tmp->prev->data[0] == 39 || tmp->prev->data[0] == '`'))
	return (-1);
    }
  return (0);
}

int			if_separator(t_liste *tmp)
{
  static int		i = 0;

  if (tmp->data[0] == '`')
    {
      if (i++ % 2 == 0 && tmp->next != NULL
	  && (tmp->next->type != CMD
	      && tmp->next->data[0] != '>'
	      && tmp->next->data[0] != '`'))
	{
	  printf("\n'%s' is not a command ! (stupid human)", tmp->next->data);
	  return (-1);
	}
      else if (tmp->prev != NULL && tmp->prev->type == TOKEN
	       && tmp->prev->data[0] != '&' && tmp->prev->data[0] != '|')
	return (-1);
    }
  return (0);
}

int			if_cmd(t_liste *tmp)
{
  if (tmp->prev != NULL)
    {
      if (tmp->prev->type == OTHER)
	return (-1);
    }
  return (0);
}

int			if_other(t_liste *tmp)
{
  if (tmp->prev == NULL)
    {
      printf("\n%s : command not found", tmp->data);
      return (-1);
    }
  return (0);
}
