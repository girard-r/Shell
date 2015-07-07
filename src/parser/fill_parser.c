/*
** fill_parser.c for 42sh in /home/joliva_d/rendu/42sh/src/parser
** 
** Made by jolivald
** Login   <joliva_d@epitech.net>
** 
** Started on  Sun Jun  1 18:38:15 2014 jolivald
** Last update Sun Jun  1 19:51:23 2014 jolivald
*/

#include <stdio.h>
#include "lexer.h"
#include "parser.h"

int		fill_parser(t_liste *params, t_env *envs)
{
  t_parser	*parser;
  t_liste	*tmp;
  int		ret;

  ret = 1;
  tmp = params;
  if ((parser = init_parser("START")) == NULL)
    return (-1);
  while (tmp != NULL)
    {
      if (tmp->type == CMD || tmp->type == OTHER || tmp->type == BUILTIN)
	if (fill_command(&tmp, parser) == -1)
	  return (-1);
      if (!tmp || tmp->type == TOKEN)
	{
	  if (test_token(&ret, &tmp, &parser, envs) == -1)
	    return (-1);
	}
      else
	return (get_error("Parsing Error"));
    }
  return (0);
}

int		test_token(int *ret, t_liste **tmp,
			   t_parser **parser, t_env *envs)
{
  *ret = 1;
  if (check_priorities(*tmp, *parser) == 1
      && (*ret = process_command_loop(*parser, envs)) == -1)
    return (-1);
  else if (!(*tmp)
	   || (*tmp && *ret == 0
	       && (*parser = init_parser("START")) == NULL))
    return (-1);
  else if (*ret == 1 && add_token(*tmp, parser) == -1)
    return (-1);
  *tmp = (*tmp)->next;
  return (0);
}

int		fill_command(t_liste **params, t_parser *parser)
{
  char		**new_argv;
  t_liste	*tmp;

  tmp = *params;
  if ((new_argv = my_realloc_add(NULL, tmp->data)) == NULL)
    return (-1);
  tmp = tmp->next;
  while (tmp && tmp->type != SEPARATOR && tmp->type != TOKEN)
    {
      if ((new_argv = my_realloc_add(new_argv, tmp->data)) == NULL)
	return (-1);
      tmp = tmp->next;
    }
  if (add_command(parser, new_argv, *params) == -1)
    return (-1);
  *params = tmp;
  return (0);
}
