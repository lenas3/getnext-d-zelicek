/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asay <asay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:45:33 by asay              #+#    #+#             */
/*   Updated: 2025/07/22 15:45:33 by asay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_length(const char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
		i++;
	write(1, "length\n", 8);
	return (i);
}

char	*ft_join(char *s1, char *s2)
{
	int		j;
	int		i;
	char	*concat;

	i = 0;
	j = 0;
	concat = malloc((ft_length(s1, '\0') + ft_length(s2, '\0') + 1) * sizeof(char));
	if (!concat)
		return (NULL);
	if (!s1 && !s2)
		return (NULL);
	if(!s1)
		return(ft_join(concat, s2));
	if(!s2)
		return(ft_join(concat, s1));
	i = ft_length(s1, '\0');
	while (s2[j] != '\0')
	{
		concat[i] = s2[j];
		i++;
		j++;
	}
	concat[i] = '\0';
	write(1, "join\n", 6);
	return (concat);
}

char *ft_read(int fd, int buff_size, char *stack)  
{
    char *buffer;

    buffer = malloc((buff_size + 1) * sizeof(char));
    if(!buffer)
		return (NULL);
    size_t bytes;
    bytes = read(fd, buffer, buff_size);
    if(bytes <= 0)
    {
        free(buffer);
        return (stack);
    }
    buffer[bytes] = '\0';
    stack = ft_join(stack, buffer);
	free (buffer); 
	write(1, "read\n", 6);
    return (stack);
}
/*
ft_read neden var ve neden veriyi stack'e atmak için tampon buffer kullanıyorum?
neden direkt olarak stack üzerine okuma yapmayalım?

geçici tampon kullanmadığım durumda stack için bellek ayrımam gerekir.
ama okuma yapmadan ne kadar ayıracağımı bilemem.
*/

char *ft_newstack(char *stack)
{
	int remainlen;
	int linelen;
	int i;
	char *newstack;

	if(!stack)
		return (NULL);
	linelen = ft_length(stack, '\n');
	remainlen = ft_length(stack, '\0');	
	if (remainlen < linelen)
	{
		free(stack);
		return(NULL);
	}
	newstack = malloc((remainlen - (linelen + 1) + 1) * sizeof(char));
	if(!newstack)
		return (NULL);
	i = 0;
	while(stack[linelen + 1 + i])
	{
		newstack[i] = stack[linelen + 1 + i];
		i++;
	}
	newstack[i] = '\0';
	free(stack);
	write(1, "newstack\n", 10);
	return(newstack);
}

char *ft_getline(char *stack)
{
	int i;

	char *line;
	i = 0;
	line = malloc((ft_length(stack, '\n') + 1) * sizeof(char));
	if(!line)
		return (NULL);
	while(stack[i])
	{
		if(stack[i] != '\n')
		{
			line[i] = stack[i];
			i++;
		}
		else
		{
			line[i] = stack[i];
			line[i++] = '\n';
			line[i+2] = '\0';
			return(line);
		}
	}
	write(1, "line\n", 6);
	return(NULL);
}
