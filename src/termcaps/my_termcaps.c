/*
** my_termcaps.c for 42sh in /home/vadee_s/rendu/42sh/termcaps
** 
** Made by vadee
** Login   <vadee_s@epitech.net>
** 
** Started on  Wed May 21 11:57:03 2014 vadee
** Last update Sun Jun  1 18:11:46 2014 jolivald
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
#include "trunc.h"
#include "builtin.h"

int		delete_char(char *tmp, int *i)
{
  int		j;
  char		save;

  j = *i - 1;
  if (*i - 1 >= 0)
    {
      if (tputs(tgetstr("le", NULL), 1, my_putchar) == ERR
      	  || tputs(tgetstr("dc", NULL), 1, my_putchar) == ERR)
	return (-1);
      while (tmp[j + 1] != 0)
	{
	  save = tmp[j + 1];
	  tmp[j] = save;
	  j += 1;
	}
      tmp[j] = 0;
      *i -= 1;
    }
  return (0);
}

char		*my_use_screen(char mode, char *str, int *i)
{
  if (mode == 11)
    {
      if (tputs(tgetstr("ce", NULL), 1, my_putchar) == ERR)
	return (NULL);
      str[*i] = 0;
    }
  else
    {
      if (tputs(tgetstr("cl", NULL), 1, my_putchar) == ERR)
	return (NULL);
      my_putstr("how_it_feels_working_on_@_clear_screen?> ");
      my_putstr(str);
    }
  return (str);
}

int		mov_curs(char *tmp, char way, int *i)
{
  if (way == 68 && *i > 0)
    {
      if (tputs(tgetstr("le", NULL), 1, my_putchar) == ERR)
	return (-1);
      *i -= 1;
    }
  else if (way == 67 && *i < (int)strlen(tmp))
    {
      if (tputs(tgetstr("nd", NULL), 1, my_putchar) == ERR)
	return (-1);
      *i += 1;
    }
  return (0);
}
