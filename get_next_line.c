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
	line = malloc(0);
	if (!buffer || !line)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read < 0)
		return (NULL);
	while (bytes_read > 0 && EOF == 0)
	{
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

int	main()
{
	int fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s \n", line);
	free(line);
	return (0);
}