/*
** get_only_cmd.c for 42sh in /home/joliva_d/rendu/42sh
** 
** Made by jolivald
** Login   <joliva_d@epitech.net>
** 
** Started on  Sat May 31 18:45:36 2014 jolivald
** Last update Sun Jun  1 22:19:32 2014 jolivald
*/

#include <stdlib.h>
#include <string.h>
#include "parser.h"

void		get_only_cmd(t_parser **parser)
{
  t_parser	*tmp;

  while (get_prio_op((*parser)->data) == 3 &&
	 strcmp((*parser)->data, "|") != 0)
    {
      tmp = *parser;
      tmp->father->son = tmp->son;
      *parser = tmp->father;
      if (tmp->son)
	{
	  tmp->son->father = tmp->father;
	  tmp->son = NULL;
	}
      tmp->father = NULL;
      free_parser(tmp);
    }
}

void		get_only_cmd_custom(t_parser **parser)
{
  t_parser	*tmp;

  while ((get_prio_op((*parser)->data) == 3 &&
	  strcmp((*parser)->data, "|") != 0))
    {
      tmp = *parser;
      tmp->father->son = tmp->son;
      *parser = tmp->father;
      if (tmp->son)
	{
	  tmp->son->father = tmp->father;
	  tmp->son = NULL;
	}
      tmp->father = NULL;
      free_parser(tmp);
    }
  smallymize(parser);
}

void	smallymize(t_parser **parser)
{
  t_parser	*tmp;

  if ((*parser)->father &&
      (get_prio_op((*parser)->data) == 3 &&
	  strcmp((*parser)->data, "|") != 0) &&
      strcmp((*parser)->father->data, "START") == 0)
    {
      tmp = *parser;
      tmp->father->son = tmp->son;
      *parser = tmp->father;
      if (tmp->son)
	{
	  tmp->son->father = tmp->father;
	  tmp->son = NULL;
	}
      tmp->father = NULL;
      free_parser(tmp);
    }
}
