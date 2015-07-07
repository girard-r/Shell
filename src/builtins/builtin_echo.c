/*
** builtin_echo.c for 42sh in /home/grout_r/rendu/42sh/42sh/builtins
** 
** Made by roman grout
** Login   <grout_r@epitech.net>
** 
** Started on  Mon May  5 15:44:38 2014 roman grout
** Last update Sun Jun  1 14:15:45 2014 jolivald
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "trunc.h"
#include "builtin.h"

static const t_backslash escape_db[8]=
  {
    {'\a','a'},
    {'\b','b'},
    {'\t','t'},
    {'\n','n'},
    {'\v','v'},
    {'\f','f'},
    {'\r','r'},
    {0, 0}
  };

char	*print_escape(char *str)
{
  int	i;
  int	j;

  j = -1;
  i = 0;
  while (str[i] != 0)
    {
      if (str[i] >= 7 && str[i] <= 13)
	{
	  while (escape_db[++j].escape != str[i]);
	  printf("\\%c", escape_db[j].occurence);
	}
      else
	printf("%c", str[i]);
      i += 1;
      j = -1;
    }
  return (str);
}

void	normal(char **arg)
{
  int	i;

  i = 0;
  while (arg[i] != NULL)
    print_escape(arg[i++]);
}

void	with_escapes(char **arg)
{
  int	i;

  i = 1;
  while (arg[i] != NULL)
    {
      my_putstr(arg[i++]);
    }
}

char	**b_echo(char **arg, char **env, int *ret)
{
  *ret = EXIT_SUCCESS;
  if (arg[1] == NULL)
    {
      my_putstr("\n");
      return (env);
    }
  if (strcmp(arg[0], "-e") == 0)
    with_escapes(arg + 1);
  else
    normal(arg + 1);
  return (env);
}
