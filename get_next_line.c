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
