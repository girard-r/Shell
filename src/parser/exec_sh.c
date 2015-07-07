/*
** exec_sh.c for exec_sh.c in /home/girard_r/Documents/PSU_2013_minishell1
** 
** Made by girard_r
** Login   <girard_r@epitech.net>
** 
** Started on  Mon Dec 16 18:56:27 2013 girard_r
** Last update Sat May 31 17:34:43 2014 jolivald
*/

#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "parser.h"

int	check_for_access_exec(char *filename)
{
  if (access(filename, F_OK) == -1)
    return (-1);
  if (access(filename, X_OK) == -1)
    {
      printf("%s: Permission denied\n", filename);
      return (-1);
    }
  return (0);
}

int	check_for_exec(char **new_av, char **envp)
{
  if (new_av[0][0] != '/' && new_av[0][0] != '.')
    return (0);
  if (check_for_access_exec(new_av[0]) == -1)
    return (0);
  if ((execve(new_av[0], new_av, envp)) == -1)
    return (-1);
  return (0);
}

int	check_path_exec(char **new_av, char **envp, char **path)
{
  int	i;
  char	*prog;

  i = -1;
  while (path[++i] != NULL)
    {
      if ((prog = malloc(sizeof(char) * (strlen(path[i])
					 + strlen(new_av[0]) + 2))) == NULL)
        return (-1);
      strcpy(prog, path[i]);
      prog[strlen(path[i])] = '/';
      prog[strlen(path[i]) + 1] = '\0';
      strcat(prog, new_av[0]);
      if (check_for_access_exec(prog) == 0
	  && execve(prog, new_av, envp) == -1)
	return (-1);
      free(prog);
    }
  if (path[i] == NULL)
    {
      printf("%s : command not found !\n", new_av[0]);
      if (kill(getpid(), SIGKILL) == -1)
	return (-1);
    }
  return (0);
}
