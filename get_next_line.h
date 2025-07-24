#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char    *get_next_line(int fd);
size_t	ft_len(char *str);
char	*ft_join(char *s1, char *s2);
char    *ft_read(int fd, int buff_size, char *stack);
char	*ft_strchr(const char *str, int a);
char *ft_newstack(char *stack);
char *ft_getline(char *stack);

#endif
