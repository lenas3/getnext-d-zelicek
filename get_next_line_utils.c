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

size_t	ft_len(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_join(char *s1, char *s2)
{
	int		j;
	int		i;
	char	*concat;

	i = 0;
	j = 0;

	if (!s1 && !s2)
		return (NULL);
	if(!s1)
		return(ft_join(concat, s2));
	if(!s2)
		return(ft_join(concat, s1));
	i = ft_len(s1);
	while (s2[j] != '\0')
	{
		concat[i] = s2[j];
		i++;
		j++;
	}
	concat[i] = '\0';
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
    return (stack);
}
/*
ft_read neden var ve neden veriyi stack'e atmak için tampon buffer kullanıyorum?
neden direkt olarak stack üzerine okuma yapmayalım?

geçici tampon kullanmadığım durumda stack için bellek ayrımam gerekir.
ama okuma yapmadan ne kadar ayıracağımı bilemem.
*/

char	*ft_strchr(const char *str, int a)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)a)
			return ((char *)&str[i]);
		i++;
	}
	if ((char)a == '\0')
		return ((char *)&str[i]);
	return (NULL);
}

