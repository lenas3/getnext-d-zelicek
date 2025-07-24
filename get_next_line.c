/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asay <asay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:45:26 by asay              #+#    #+#             */
/*   Updated: 2025/07/22 15:45:26 by asay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_newstack(char *stack)
{
	int fullen;
	int i;
	char *newstack;
	char *lineptr;

	if(!stack)
		return (NULL);
	lineptr = ft_strchr(stack, '\n');
	if (!lineptr)
		return (free(stack), NULL);
	fullen = ft_len(stack) - (lineptr - stack + 1);	
	newstack = malloc((fullen + 1) * sizeof(char));
	if(!newstack)
		return (NULL);
	i = 0;
	while(stack[(lineptr - stack) + 1 + i])
	{
		newstack[i] = stack[(lineptr - stack ) + 1 + i];
		i++;
	}
	newstack[i] = '\0';
	free(stack);
	return(newstack);
}

char *ft_getline(char *stack)
{
	int i;
	int j;
	char *line;
	
	i = 0;
	j = 0;
	while(stack[i] && stack[i] != '\n')
		i++;
	if(stack[i] == '\n')
		i++;
	line = malloc((i + 1) * sizeof(char));
	if(!line)
		return (NULL);	
	while(j <= i)
	{
		line[j] = stack[j];
		j++;
	}
	line[j] = '\n';
	return(line);
}

char *get_next_line(int fd)
{
	static char *stack;
    char *line;
    int len_line;
    int i;

    if(fd < 0 || BUFFER_SIZE < 0)
        return (NULL);
    stack = ft_read(fd, BUFFER_SIZE, stack);
    stack = ft_newstack(stack);
    line = ft_getline(stack);
    return (line);
}
