/*
** my_power_rec.c for ex4 in /home/vadee_s/rendu/Piscine-C-Jour_05
** 
** Made by vadee_s
** Login   <vadee_s@epitech.net>
** 
** Started on  Sun Oct  6 16:59:35 2013 vadee_s
** Last update Thu Oct 24 16:16:44 2013 vadee_s
*/

int	my_power_rec(int nb, int pwr)
{
  if (pwr == 1 || nb == 1)
    return (nb);
  else if (pwr == 0)
    return (1);
  else
    return (nb * my_power_rec(nb, pwr - 1));
}
