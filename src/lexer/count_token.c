/*
** count_token.c for 42sh in /home/vadee_s/rendu/42sh/42sh/lexer
** 
** Made by vadee
** Login   <vadee_s@epitech.net>
** 
** Started on  Tue May  6 19:08:03 2014 vadee
** Last update Sat May 10 19:02:07 2014 vadee_s
*/

#include <stdlib.h>
#include "lexer.h"

int		count_quotes(t_liste *list)
{
  t_liste	*tmp;
  int		count1;
  int		count2;
  int		count3;

  count1 = 0;
  count2 = 0;
  count3 = 0;
  tmp = list;
  while (tmp != NULL)
    {
      if (tmp->data[0] == 39)
	count1 +=1;
      else if (tmp->data[0] == '`')
	count2 += 1;
      else if (tmp->data[0] == '"')
	count3 += 1;
      tmp = tmp->next;
    }
  if (count1 % 2 != 0 || count2 % 2 != 0 || count3 % 2 != 0)
    return (-1);
  return (0);
}

int		count_parenthesis(t_liste *list)
{
  t_liste	*tmp;
  int		count1;
  int		count2;

  count1 = 0;
  count2 = 0;
  tmp = list;
  while (tmp != NULL)
    {
      if (tmp->data[0] == '(')
	count1 +=1;
      else if (tmp->data[0] == ')')
	count2 += 1;
      tmp = tmp->next;
    }
  if (count1 != count2)
    return (-1);
  return (0);
}

int		count_braces(t_liste *list)
{
  t_liste	*tmp;
  int		count1;
  int		count2;

  count1 = 0;
  count2 = 0;
  tmp = list;
  while (tmp != NULL)
    {
      if (tmp->data[0] == '}')
	count1 +=1;
      else if (tmp->data[0] == '{')
	count2 += 1;
      tmp = tmp->next;
    }
  if (count1 != count2)
    return (-1);
  return (0);
}

int		count_tokens(t_liste *list)
{
  if (count_quotes(list) == -1
      || count_parenthesis(list) == -1
      || count_braces(list) == -1)
    return (-1);
  else
    return (0);
}
