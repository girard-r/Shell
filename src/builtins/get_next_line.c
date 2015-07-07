/*
** get_next_line.c for gnl in /home/grout_r/rendu/Sudoki-Bi
** 
** Made by roman grout
** Login   <grout_r@epitech.net>
** 
** Started on  Sat Mar  1 00:29:54 2014 roman grout
** Last update Sun Jun  1 13:52:26 2014 jolivald
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "builtin.h"

char	*myaddstr(char *str, int i)
{
  char	*tmp;

  if ((tmp = malloc(i + 2 + 1)) == NULL)
    return (NULL);
  *tmp = 0;
  strcat(tmp, str);
  free(str);
  return (tmp);
}

char		*get_next_line(const int fd)
{
  static char	buffer[1];
  int		i;
  int		c;
  char		*str;

  i = 0;
  if ((str = malloc(1 + 2)) == NULL)
    return (NULL);
  if ((c = read(fd, buffer, 1)) <= 0)
    return (NULL);
  while (c != 0)
    {
      if (buffer[0] == '\n' || buffer[0] == '\0')
	{
	  str = strcat(str, "\n");
	  return (str);
	}
      str[i] = buffer[0];
      str[i + 1] = '\0';
      str = myaddstr(str, i);
      if ((c = read(fd, buffer, 1)) <= 0)
	return (NULL);
      i = i + 1;
    }
  return (str);
}
