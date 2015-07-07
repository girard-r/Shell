/*
** priority.c for priority.c in /home/girard_r/42sh/parser
** 
** Made by girard_r
** Login   <girard_r@epitech.net>
** 
** Started on  Sun May 18 18:42:53 2014 girard_r
** Last update Sat May 31 17:37:48 2014 jolivald
*/

#include <stdlib.h>
#include <string.h>
#include "parser.h"

static const t_priorities	g_priorities[11] =
  {
    {">>", 3},
    {"<<", 3},
    {"<", 3},
    {">", 3},
    {"||", 0},
    {"|", 3},
    {"&&", 0},
    {";", -1},
    {"START", 0},
    {NULL, -1}
  };

int		get_prio_op(char *op)
{
  int		i;

  i = 0;
  while (g_priorities[i].operator)
    {
      if (!strcmp(g_priorities[i].operator, op))
	return (g_priorities[i].priority);
      i += 1;
    }
  return (0);
}

int		check_priorities(t_liste *param, t_parser *parser)
{
  if (!param || (get_prio_op(param->data) < get_prio_op(parser->data)))
    return (1);
  else
    return (0);
}
