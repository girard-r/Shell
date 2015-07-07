/*
** get_next_line.c for get_next_line.c in /home/girard_r/Documents/get_next_line-2017-girard_r
** 
** Made by girard_r
** Login   <girard_r@epitech.net>
** 
** Started on  Wed Nov 13 18:24:15 2013 girard_r
** Last update Sun Dec  1 10:28:48 2013 girard_r
*/

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

char	*get_str_line(char *buffer, int *pos, int pos_next)
{
  char	*str;
  int	j;

  j = 0;
  str = malloc(sizeof(char) * (pos_next - *pos) + 1);
  if (str == NULL)
    return (NULL);
  while (*pos < pos_next)
    {
      str[j] = buffer[*pos];
      *pos = *pos + 1;
      j = j + 1;
    }
  str[j] = '\0';
  return (str);
}

char	*my_realloc(char *buffer, char *tmp, int *pos, int pos_next)
{
  char	*str;
  int	max_tmp;
  int	i;

  i = 0;
  max_tmp = 0;
  while (tmp[max_tmp] != 0)
    max_tmp = max_tmp + 1;
  str = malloc((max_tmp + pos_next - *pos + 1) * sizeof(char));
  if (str == NULL)
    return (NULL);
  while (tmp[i] != '\0')
    {
      str[i] = tmp[i];
      i = i + 1;
    }
  while (*pos < pos_next)
    {
      str[max_tmp] = buffer[*pos];
      *pos = *pos + 1;
      max_tmp = max_tmp + 1;
    }
  str[max_tmp + pos_next - *pos] = '\0';
  free(tmp);
  return (str);
}

char	*check_backslash_begin(char *buffer, int *pos, char *tmp)
{
  if (buffer[*pos] == '\n')
    {
      *pos = *pos + 1;
      tmp = malloc(sizeof(char) * 1);
      if (tmp == NULL)
	return (NULL);
      *tmp = '\0';
      return (tmp);
    }
  else
    return (NULL);
}

char	*process_line(char *buffer, int *pos, int rep)
{
  int	i;
  int	pos_next;
  char	*tmp;

  i = 0;
  pos_next = *pos;
  while (buffer[pos_next] != 0 && buffer[pos_next] != '\n')
    pos_next = pos_next + 1;
  if (rep == 1)
    tmp = my_realloc(buffer, tmp, pos, pos_next);
  else if (rep == 0)
    tmp = get_str_line(buffer, pos, pos_next);
  if (buffer[*pos] == 0)
    {
      while (buffer[i] != 0)
	{
	  buffer[i] = '\0';
	  i = i + 1;
	}
      *pos = 0;
    }
  return (tmp);
}

char		*get_next_line(const int fd)
{
  static char	buffer[BUFFER_SIZE];
  int		ret;
  static int	pos = 0;
  int		rep;
  char		*tmp;

  rep = 0;
  if ((tmp = check_backslash_begin(buffer, &pos, tmp)) != NULL)
    return (tmp);
  while (buffer[pos] != '\n')
    {
      if (pos == 0)
	{
	  ret = read(fd, buffer, BUFFER_SIZE);
	  if (ret == 0 && tmp != NULL)
	    return (tmp);
	  else if (tmp != NULL && ret > 0)
	    rep = 1;
	  else if (ret == -1 || ret == 0)
	    return (NULL);
	}
      tmp = process_line(buffer, &pos, rep);
    }
  pos = pos + 1;
  return (tmp);
}
