#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

size_t	ft_length(const char *str, char c);
char    *ft_read(int fd, int buff_size, char *stack);
char *ft_newstack(char *stack);
char    *get_next_line(int fd);
char *ft_getline(char *stack);

#endif
