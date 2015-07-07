/*
** get_entry.c for 42sh - lexer in /home/vadee_s/rendu/42sh/42sh/lexer
** 
** Made by vadee
** Login   <vadee_s@epitech.net>
** 
** Started on  Wed Apr 23 19:01:00 2014 vadee
** Last update Sat May 24 18:19:05 2014 vadee
*/

#include <stdio.h>
#include "lexer.h"

void		print_list(t_liste *list)
{
  t_liste	*tmp;

  tmp = list;
  my_putchar(10);
  while (tmp != NULL)
    {
      printf("%s | %d\n", tmp->data, tmp->type);
      tmp = tmp->next;
    }
}

t_liste		*get_entry(char *str, char **path, char **env)
{
  char		**cmd;
  t_liste	*list;

  if ((cmd = my_str_to_wordtab_sh(str)) == NULL
      || (list = linked_list(cmd)) == NULL)
    return (NULL);
  define_type(list, path);
  if (process_error(list) == -1
      || (list = find_env_variables(list, env)) == NULL)
    return (NULL);
  list = regroup_args(list);
  if (check_order(list) == -1)
    return (NULL);
  return (list);
}
