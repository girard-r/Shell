/*
** my_realloc_tab.c for my_realloc_add.c in /home/girard_r/42sh/parser
** 
** Made by girard_r
** Login   <girard_r@epitech.net>
** 
** Started on  Sat May 10 01:30:39 2014 girard_r
** Last update Sun May 18 17:57:55 2014 girard_r
*/

#include <stdlib.h>
#include <string.h>

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = 0;
  return (dest);
}

char	*my_strdup(char *src)
{
  char	*dest;

  if ((dest = malloc(sizeof(char) * (strlen(src) + 1))) == NULL)
    return (NULL);
  my_strcpy(dest, src);
  return (dest);
}

int		tab_len(char **tab)
{
  int		cmp;

  cmp = 0;
  if (tab != NULL)
    {
      while (tab[cmp] != NULL)
	cmp += 1;
    }
  return (cmp);
}

char		**my_realloc_add(char **model, char *str)
{
  char		**new_av;
  int		i;

  i = 0;
  if ((new_av = malloc(sizeof(char *) * (tab_len(model) + 2))) == NULL)
    return (NULL);
  while (model && model[i])
    {
      new_av[i] = model[i];
      i += 1;
    }
  new_av[i] = str;
  new_av[i + 1] = NULL;
  if (model != NULL)
    free(model);
  return (new_av);
}
