/*
** free.c for 42sh in /home/joliva_d/rendu/42sh/src/parser
** 
** Made by jolivald
** Login   <joliva_d@epitech.net>
** 
** Started on  Sun Jun  1 18:26:40 2014 jolivald
** Last update Sun Jun  1 18:27:29 2014 jolivald
*/

#include <stdlib.h>
#include "parser.h"

int		free_tab(char **tab)
{
  int		i;

  i = 0;
  if (!tab)
    return (0);
  while (tab[i])
    {
      free(tab[i]);
      tab[i] = NULL;
      i += 1;
    }
  free(tab);
  return (0);
}

int		free_parser(t_parser *parser)
{
  t_parser	*tmp;

  while (parser)
    {
      tmp = parser->son;
      parser->command->new_argv = NULL;
      free(parser->command);
      parser->command = NULL;
      free(parser);
      parser = tmp;
      if (tmp)
	tmp->father = NULL;
    }
  return (0);
}
