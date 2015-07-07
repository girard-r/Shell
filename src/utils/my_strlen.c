/*
** my_strlen.c for 42sh in /home/joliva_d/rendu/42sh/src/utils
** 
** Made by jolivald
** Login   <joliva_d@epitech.net>
** 
** Started on  Thu May 29 13:28:50 2014 jolivald
** Last update Thu May 29 13:29:36 2014 jolivald
*/

int		my_strlen(char *s)
{
  register int	i;

  i = -1;
  while (s[++i]);
  return (i);
}
