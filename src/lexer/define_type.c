/*
** define_type.c for 42sh in /home/grout_r/rendu/42sh/42sh/lexer
** 
** Made by roman grout
** Login   <grout_r@epitech.net>
** 
** Started on  Wed Apr 23 23:01:21 2014 roman grout
** Last update Sun Jun  1 16:23:16 2014 jolivald
*/

#include <stdlib.h>
#include <string.h>
#include "lexer.h"

void		define_type_loop(t_liste *tmp, char **path)
{
  if (is_builtin(tmp->data) == 0)
    tmp->type = BUILTIN;
  else if (is_token(tmp->data) == 0)
    tmp->type = TOKEN;
  else if (is_separator(tmp->data) == 0)
    tmp->type = SEPARATOR;
  else if (is_cmd(tmp->data, path) == 0 || tmp->prev == NULL
    || tmp->prev->type == TOKEN)
    tmp->type = CMD;
  else
    tmp->type = OTHER;
}

void		define_type(t_liste *racine, char **path)
{
  t_liste		*tmp;

  tmp = racine;
  while (tmp != NULL)
    {
      define_type_loop(tmp, path);
      tmp = tmp->next;
    }
}
