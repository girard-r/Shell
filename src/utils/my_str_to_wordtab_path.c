/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/vadee_s/rendu/Piscine-C-Jour_08/ex_04
** 
** Made by vadee_s
** Login   <vadee_s@epitech.net>
** 
** Started on  Thu Oct 11 17:32:01 2013 vadee_s
** Last update Tue Dec 17 18:31:17 2013 vadee
*/

#include <stdlib.h>

static int     word_nbr(char *str)
{
  int	count;
  int	i;

  i = 0;
  count = 0;
  while (str[i] != 0)
    {
      if (str[i] != ':' && str[i] != '=')
        {
          count = count + 1;
          while (str[i] && (str[i] != ':' && str[i] != '='))
	    i = i + 1;
        }
      else
	i = i + 1;
    }
  return (count);
}

static int	my_char_isnum(char c)
{
  if (c != ':' && c != '=')
    return (1);
  else
    return (0);
}

static void    	fill_tab(char *tab, char *str, int i, int stock)
{
  int		j;

  j = 0;
  while (stock != i)
    tab[j++] = str[stock++];
  tab[j] = '\0';
}

char		**my_str_to_wordtab_path(char *str)
{
  int		i;
  int		j;
  char		**tab;
  int		stock;

  j = 0;
  i = 0;
  if ((tab = malloc((word_nbr(str) + 1) * sizeof(char*))) == NULL)
    return (NULL);
  while (str[i] != '\0')
    {
      stock = i;
      while (my_char_isnum(str[i]) == 1 && str[i] != '\0')
	i = i + 1;
      if ((tab[j] = malloc(sizeof(char) * (i - stock) + 1)) == NULL)
	return (NULL);
      fill_tab(tab[j], str, i, stock);
      j++;
      while (my_char_isnum(str[i]) == 0)
	i = i + 1;
    }
  tab[j] = NULL;
  return (tab);
}
