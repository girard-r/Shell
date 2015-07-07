/*
** get_next_line.h for getnextline.h in /home/girard_r/Documents/get_next_line-2017-girard_r
** 
** Made by girard_r
** Login   <girard_r@epitech.net>
** 
** Started on  Wed Nov 13 18:19:25 2013 girard_r
** Last update Sun Dec  1 10:29:01 2013 girard_r
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

# define BUFFER_SIZE 1024

char	*get_next_line(const int fd);
char	*get_str_line(char *buffer, int *pos, int pos_next);
char	*my_realloc(char *buffer, char *tmp, int *pos, int pos_next);
char	*check_backslash_begin(char *buffer, int *pos, char *tmp);
char	*process_line(char *buffer, int *pos, int rep);

#endif /* !GET_NEXT_LINE_H_ */
