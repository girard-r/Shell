/*
** builtin_history.c for 42sh in /home/grout_r/rendu/42sh/42sh/builtins
** 
** Made by roman grout
** Login   <grout_r@epitech.net>
** 
** Started on  Mon May  5 15:42:58 2014 roman grout
** Last update Sun Jun  1 18:03:59 2014 jolivald
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

char	**b_history(char **arg, char **env, int *ret)
{
  int	fd;
  int	debug;
  char	is_read[2];
  char	**tmp;

  tmp = arg;
  tmp += 1;
  debug = 42;
  if ((fd = open("/tmp/.42shistory",
		 O_CREAT | O_APPEND | O_RDWR, 00664)) == -1)
    {
      perror("Open Errortoto");
      return (NULL);
    }
  while (debug != 0)
    {
      if ((debug = read(fd, is_read, 1)) < 0)
	{
	  *ret = 1;
	  return (env);
	}
      printf("%c", is_read[0]);
    }
  return (env);
}
