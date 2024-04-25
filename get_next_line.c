/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesilva- <pesilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 08:56:09 by pesilva-          #+#    #+#             */
/*   Updated: 2024/04/25 08:56:09 by pesilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
    char	*line;
    char	*buffer;
    char	*temp;
    int		bytes_read;

    buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buffer)
        return (NULL);
    bytes_read = read(fd, buffer, BUFFER_SIZE);
    while (bytes_read > 0)
    {
        buffer[bytes_read] = '\0';
        if (ft_strchr(buffer, '\n'))
        {
            line = ft_strjoin(line, buffer);
            free(buffer);
            return (line);
        }
        temp = ft_strjoin(line, buffer);
        free(line);
        line = temp;
        bytes_read = read(fd, buffer, BUFFER_SIZE);
    }
    free(buffer);
    return (line);
}