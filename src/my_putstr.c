/*
** my_putstr.c for Exercice2_Piscine_C_Jour04 in /home/vadee_s/rendu/Piscine-C-Jour_04
** 
** Made by vadee_s
** Login   <vadee_s@epitech.net>
** 
** Started on  Thu Oct  3 12:21:56 2013 vadee_s
** Last update Sat May 10 17:20:10 2014 vadee_s
*/

#include <unistd.h>

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != 0)
    i++;
  write(1, str, i);
}
