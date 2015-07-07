/*
** builtin_exit.c for 42sh in /home/grout_r/rendu/42sh/42sh/builtins
** 
** Made by roman grout
** Login   <grout_r@epitech.net>
** 
** Started on  Mon May  5 15:39:24 2014 roman grout
** Last update Sun Jun  1 14:20:23 2014 jolivald
*/

#include <stdlib.h>

void	b_free_tab(char **b_tab)
{
  int	i;

  i = 0;
  while (b_tab[i] != NULL)
    {
      free(b_tab[i]);
      i += 1;
    }
  free(b_tab);
}

static int	is_neg(char *str)
{
  int		i;
  int		counter;

  i = 0;
  counter = 0;
  while (str[i] > '9' || str[i] < '0')
    {
      if (str[i] == '-')
	counter++;
      i++;
    }
  if (counter % 2 != 0)
    return (1);
  else
    return (0);
}

static int	is_num(char l)
{
  if (l >= '0' && l <= '9')
    return (1);
  else
    return (0);
}

static int	my_getnbr(char *str)
{
  int		i;
  int		nbr;

  nbr = 0;
  i = 0;
  while (is_num(str[i]) == 0)
    i++;
  while (is_num(str[i]) == 1)
    {
      nbr = ((nbr * 10) + (str[i] - 48));
      i++;
    }
  if (is_neg(str) == 1)
    nbr = -nbr;
  return (nbr);
}
char	**b_exit(char **arg, char **env, int *ret)
{
  b_free_tab(env);
  if (arg[1])
    *ret = my_getnbr(arg[1]);
  *ret = EXIT_SUCCESS;
  return (NULL);
}
