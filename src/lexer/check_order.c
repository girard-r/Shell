/*
** check_order.c for 42sh in /home/vadee_s/rendu/42sh/lexer
** 
** Made by vadee
** Login   <vadee_s@epitech.net>
** 
** Started on  Sun May 11 20:48:56 2014 vadee
** Last update Sat May 31 21:11:27 2014 vadee
*/

#include <stdio.h>
#include <string.h>
#include "lexer.h"

static const t_ptrfunc	tab[6] =
  {
    {BUILTIN, &if_cmd},
    {TOKEN, &if_token},
    {SEPARATOR, &if_separator},
    {CMD, &if_cmd},
    {OTHER, &if_other},
    {0, NULL}
  };

int			loop_order(t_liste *tmp)
{
  int			i;
  int			ret;

  i = -1;
  while (tab[++i].fptr != NULL)
    {
      if (tmp->type == tab[i].type)
	return (ret = tab[i].fptr(tmp));
    }
  return (0);
}

int			check_order(t_liste *list)
{
  t_liste		*tmp;

  tmp = list;
  while (tmp != NULL)
    {
      if (loop_order(tmp) == -1)
	{
	  printf("\nWrong syntax in command line near element '%s' !\n",
		 tmp->data);
	  return (-1);
	}
      tmp = tmp->next;
    }
  return (0);
}
