/*
** add_history.c for 42sh in /home/ngo-va_a/rendu/42sh/builtins
** 
** Made by ngo-va_a
** Login   <ngo-va_a@epitech.net>
** 
** Started on  Sun May 25 15:19:53 2014 ngo-va_a
** Last update Sun Jun  1 17:59:27 2014 jolivald
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "builtin.h"

int	my_putfile(char a, int fd)
{
  if (write(fd, &a, 1) <= 0)
    return (-1);
  return (0);
}

void	my_put_nbr_file(int nb, int fd)
{
  int		neg;

  neg = 0;
  if (nb < 0)
    {
      my_putfile('-', fd);
      if (nb == -2147483648)
        {
          neg = 1;
          nb++;
        }
      nb = nb * -1;
    }
  if (nb >= 10)
    my_put_nbr_file(nb / 10, fd);
  if (neg == 1)
    {
      neg = 0;
      my_putfile(nb % 10 + '1', fd);
    }
  else
    my_putfile(nb % 10 + '0', fd);
}

int	add_one(int fd, char *cmd, int pos)
{
  my_put_nbr_file(pos, fd);
  if (write(fd, "\t", 1) <= 0)
    return (-1);
  if (write(fd, cmd, strlen(cmd)) <= 0)
    return (-1);
  if (write(fd, "\n", 1) <= 0)
    return (-1);
  return (0);
}

int	add_history(char *cmd)
{
  static int	pos = 0;
  int		fd;

  if (pos == 0)
    {
      if ((fd = open("/tmp/.42shistory",
		     O_CREAT | O_TRUNC | O_WRONLY, 00664)) == -1)
	return (-1);
      add_one(fd, cmd, pos);
      pos++;
      if (close(fd) == -1)
	return (-1);
    }
  else
    {
      if ((fd = open("/tmp/.42shistory", O_APPEND | O_WRONLY)) == -1)
	return (-1);
      add_one(fd, cmd, pos);
      pos++;
      if (close(fd) == -1)
	return (-1);
    }
  return (0);
}
