/*
** suppr_elelem_list.c for suppr_elem_list in /home/vadee_s/rendu/CPE_2013_Pushswap/src
** 
** Made by vadee
** Login   <vadee_s@epitech.net>
** 
** Started on  Sat Dec 21 19:42:44 2013 vadee
** Last update Wed May 21 11:10:29 2014 vadee
*/
#include <stdlib.h>
#include "../lexer/lexer.h"

void		suppr_elem_list(t_liste *elem)
{
  if (elem->prev != NULL)
    elem->prev->next = elem->next;
  if (elem->next != NULL)
    elem->next->prev = elem->prev;
  free(elem);
}
