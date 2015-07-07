/*
** parser.c for parser.c in /home/girard_r/42sh/parser
** 
** Made by girard_r
** Login   <girard_r@epitech.net>
** 
** Started on  Sat May 10 00:27:39 2014 girard_r
** Last update Sun Jun  1 18:39:30 2014 jolivald
*/

#include <stdlib.h>
#include "parser.h"
#include "lexer.h"

t_parser	*init_parser(char *elem)
{
  t_parser	*parser;

  if ((parser = malloc(sizeof(t_parser))) == NULL)
    return (NULL);
  parser->data = elem;
  parser->son = NULL;
  parser->command = NULL;
  parser->father = NULL;
  return (parser);
}

int		add_in_parser(char *elem, t_parser **father)
{
  t_parser	*parser;

  if ((parser = malloc(sizeof(t_parser))) == NULL)
    return (-1);
  parser->data = elem;
  parser->son = NULL;
  parser->command = NULL;
  parser->father = *father;
  (*father)->son = parser;
  *father = parser;
  return (0);
}

int		add_token(t_liste *params, t_parser **parser)
{
  if (params && (add_in_parser(params->data, parser)) == -1)
    return (-1);
  return (0);
}

int		add_command(t_parser *parser, char **new_argv, t_liste *param)
{
  t_command	*command;

  if ((command = malloc(sizeof(t_command))) == NULL)
    return (-1);
  command->pipefd[0] = -1;
  command->pipefd[1] = -1;
  command->pid = 0;
  command->is_builtin = 0;
  if (param->type == BUILTIN)
    command->is_builtin = 1;
  command->new_argv = new_argv;
  parser->command = command;
  return (0);
}
