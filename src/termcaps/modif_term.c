/*
** modif_term.c for  in /home/vadee_s/rendu/PSU_2013_my_select
** 
** Made by vadee_s
** Login   <vadee_s@epitech.net>
** 
** Started on  Wed Jan 15 11:56:37 2014 vadee_s
** Last update Sun Jun  1 18:14:50 2014 jolivald
*/

#include <ncurses/curses.h>
#include <term.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "trunc.h"
#include <termios.h>

int		init_termcaps(struct termios *term,
			      struct termios *init, char **env)
{
  int		i;

  i = -1;
  if (tcgetattr(0, term) == -1 || tcgetattr(0, init) == -1)
    return (-1);
  while (env[++i] != NULL && strncmp(env[i], "TERM=", 5) != 0);
  if (env[i] != NULL)
    {
      if (tgetent(0, env[i] + 5) != 1)
	return (-1);
    }
  else
    {
      my_putstr("Variable TERM not found\n");
      my_putstr("Failed to initialize termcaps\n");
      return (-1);
    }
  return (0);
}

int		raw_mode(struct termios *term)
{
  term->c_lflag &= ~ICANON;
  term->c_cc[VMIN] = 1;
  term->c_cc[VTIME] = 0;
  if (tcsetattr(0, 0, term) == -1)
    return (-1);
  return (0);
}

int		print_mode_off(struct termios *term)
{
  term->c_lflag &= ~ECHO;
  if (tcsetattr(0, 0, term) == -1)
    return (-1);
  return (0);
}

int		print_mode_on(struct termios *term)
{
  term->c_lflag &= ECHO;
  if (tcsetattr(0, 0, term) == -1)
    return (-1);
  return (0);
}
