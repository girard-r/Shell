/*
** my_str_to_wordtab2.c for my_str_to_wordtab2 in /home/ngo-va_a/rendu/Piscine-C-Jour_08/ex_04
** 
** Made by ngo-va_a
** Login   <ngo-va_a@epitech.net>
** 
** Started on  Fri Oct 11 13:45:18 2013 ngo-va_a
** Last update Sun Jun  1 14:05:51 2014 jolivald
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "builtin.h"

int		fill_tab2(char **b_tab, char *str, int pos, int pos_next)
{
  static int	j = 0;
  int		k;

  k = 0;
  if (pos == 0)
    j = 0;
  if ((b_tab[j] = malloc(sizeof(char) * (pos_next - pos + 1))) == NULL)
    return (-1);
  while (k < pos_next - pos)
    {
      b_tab[j][k] = str[pos + k];
      k = k + 1;
    }
  b_tab[j][k] = '\0';
  j = j + 1;
  return (j);
}

int	total_words2(char *str)
{
  int	i;
  int	count;

  i = 0;
  count = 0;
  while (str[i] != '\0')
    {
      while (str[i] != '\0' && (str[i] == ':' || str[i] == '='))
	i = i + 1;
      if (str[i] != '\0' && (str[i] != ':' && str[i] != '='))
	{
	  while (str[i] != '\0' && (str[i] != ':' && str[i] != '='))
	    i = i + 1;
	  count = count + 1;
	}
    }
  return (count);
}

char	**my_str_to_wordtab2(char *str)
{
  char	**b_tab;
  int	save;
  int	i;
  int	len;

  i = 0;
  len = total_words2(str);
  if ((b_tab = malloc((len + 1) * sizeof(char *))) == NULL)
    return (NULL);
  while (str[i] != '\0')
    {
      while (str[i] && ((str[i] == ':' || str[i] == '=')))
	i = i + 1;
      save = i;
      while (str[i] && ((str[i] != ':' && str[i] != '=')))
	i = i + 1;
      len = fill_tab2(b_tab, str, save, i);
    }
  b_tab[len] = NULL;
  return (b_tab);
}
