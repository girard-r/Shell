/*
** misc.c for 42sh in /home/vadee_s/rendu/42sh/termcaps
** 
** Made by vadee
** Login   <vadee_s@epitech.net>
** 
** Started on  Wed May 21 12:05:16 2014 vadee
** Last update Sat May 24 12:53:47 2014 vadee
*/

#include <unistd.h>
#include <stdlib.h>

int		my_putchar(int c)
{
  write(1, &c, 1);
  return (0);
}

void		clean_buff(char *s)
{
  int		i;

  i = -1;
  while (++i != 4)
    s[i] = 0;
}

int		is_printable(char *s)
{
  if (s[0] >= 32 && s[0] < 127)
    return (0);
  else
    return (-1);
}

char		*check_cmd_line(char *tmp, int ret)
{
  if (*tmp == 0 || ret == -1)
    return (NULL);
  return (tmp);
}

int		is_interactive(int isenv, char *s)
{
  if (isenv == 0 && *s == 4)
    return (0);
  else
    return (1);
}
