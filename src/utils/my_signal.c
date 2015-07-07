/*
** signal.c for signal in /home/vadee_s/rendu/PSU_2013_minishell1
** 
** Made by vadee
** Login   <vadee_s@epitech.net>
** 
** Started on  Wed Dec 18 13:48:40 2013 vadee
** Last update Sun Jun  1 18:15:32 2014 jolivald
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include "trunc.h"

void		react_signal(int sig)
{
  my_putstr("\ndo_not_use_ctrl_wh@tever(it hurts)$> ");
  sig += 1;
}

int		if_signal()
{
  if (signal(SIGINT, react_signal) == SIG_ERR)
    return (-1);
  if (signal(SIGTSTP, react_signal) == SIG_ERR)
    return (-1);
  if (signal(SIGQUIT, react_signal) == SIG_ERR)
    return (-1);
  if (signal(SIGABRT, react_signal) == SIG_ERR)
    return (-1);
  return (0);
}
