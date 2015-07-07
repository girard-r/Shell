/*
** get_command_line.c for 42sh in /home/vadee_s/rendu/42sh/42sh
** 
** Made by vadee
** Login   <vadee_s@epitech.net>
** 
** Started on  Fri May  9 15:57:52 2014 vadee
** Last update Sun Jun  1 18:13:31 2014 jolivald
*/

#include <ncurses/curses.h>
#include <term.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "builtin.h"
#include "trunc.h"

int	g_is_env;

char		*init_get_cmd(int fd, struct termios *term, char *s, char *tmp)
{
  if ((tmp = malloc(4)) == NULL
      || fd < 0)
    return (NULL);
  else if (g_is_env == 0 &&
	   (print_mode_off(term) == -1 || raw_mode(term) == -1))
    return (NULL);
  clean_buff(s);
  clean_buff(tmp);
  return (tmp);
}

char		*get_prev_cmd(int pos, char *tmp, int *i)
{
  char		back[4];
  char		*ret;

  if ((ret = search_history(pos)) != NULL)
    {
      back[0] = 27;
      back[1] = 91;
      back[2] = 68;
      back[3] = 0;
      while (*i != 0)
      	my_curs(back, tmp, i);
      if (tputs(tgetstr("ce", NULL), 1, my_putchar) == ERR)
      	return (NULL);
      *i = strlen(ret) - 1;
      ret[strlen(ret) - 1] = 0;
      my_putstr(ret);
      return (ret);
    }
  return (NULL);
}

char		*my_curs(char *s, char *tmp, int *i)
{
  static int	pos = 0;
  char		*save;

  if (g_is_env != 0)
    return (tmp);
  if (s[0] == 127 && s[1] == 0 && delete_char(tmp, i) == -1)
    return (NULL);
  else if (s[0] == 27 && s[1] == 91 && (s[2] == 67 || s[2] == 68)
	   && s[3] == 0 && mov_curs(tmp, s[2], i) == -1)
    return (NULL);
  else if (s[0] == 27 && s[1] == 91 &&
	   (s[2] == 65 || s[2] == 66) && s[3] == 0)
    {
      if (s[2] == 65)
	pos += 1;
      else if (s[2] == 66 && pos > 0)
	pos -= 1;
      if (pos > 0 && (save = get_prev_cmd(pos, tmp, i)) != NULL)
	tmp = strdup(save);
      else if (pos > 1 && save == NULL)
	pos -= 1;
    }
  else if ((s[0] == 11 || s[0] == 12) && s[1] == 0)
    tmp = my_use_screen(s[0], tmp, i);
  return (tmp);
}

char		*print_char(char *tmp, char c, int *i, struct termios *term)
{
  if (is_printable(&c) == 0)
    {
      if ((tmp = realloc(tmp, strlen(tmp) + 2)) == NULL)
	return (NULL);
      putchar_in_string(tmp, c, *i);
      if (g_is_env == 0 && print_mode_on(term) == -1)
	return (NULL);
      my_putchar(c);
      *i += 1;
      if (g_is_env == 0 && *i < (int)strlen(tmp) && puts_end(tmp, i) == -1)
	return (NULL);
      if (g_is_env == 0 && print_mode_off(term) == -1)
	return (NULL);
      return (tmp);
    }
  return (tmp);
}

char		*get_command_line(int fd, struct termios *term)
{
  char		s[4];
  char		*tmp;
  int		ret;
  int		i;

  i = 0;
  tmp = NULL;
  if ((tmp = init_get_cmd(fd, term, s, tmp)) == NULL)
    return (NULL);
  while ((ret = read(fd, s, 4)) > 0 && (tmp = my_curs(s, tmp, &i))
    	 && is_interactive(g_is_env, s) == 1)
    {
      if ((s[0] == 10 || s[0] == 0) && s[1] == 0)
	return (tmp);
      else if ((tmp = print_char(tmp, s[0], &i, term)) == NULL)
	return (NULL);
      clean_buff(s);
    }
  return (check_cmd_line(tmp, ret));
}
