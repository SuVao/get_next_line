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

char	*get_nl(int fd, char *s)
{
	char	buffer[BUFFER_SIZE + 1];
	int		bytes_read;
	int		i;

	i = 0;
	while (i < BUFFER_SIZE)
		buffer[i++] = '\0';
	bytes_read = 1;
	while (!ft_strchr(buffer, '\n') && bytes_read)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0 || (!bytes_read && !s))
			return (NULL);
		buffer[bytes_read] = '\0';
		if (!s)
			s = ft_strdup(buffer);
		else
			s = ft_strjoin(s, buffer);
		if (!s)
			return (NULL);
	}
	return (s);
}

char	*get_next_line(int fd)
{
	static char	*ori_str;
	char		*final_boss;
	char		*rest_of_chars;
	size_t		i;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	ori_str = get_nl(fd, ori_str);
	if (!ori_str)
		return (NULL);
	i = 0;
	while (ori_str[i] != '\n' && ori_str[i])
		i++;
	if (ori_str[i] == '\n')
		i++;
	final_boss = ft_substr(ori_str, 0, i);
	rest_of_chars = ft_substr(ori_str, i, ft_strlen(ori_str) - i);
	free (ori_str);
	ori_str = rest_of_chars;
	return (final_boss);
}

/* int	main()
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("Line: %s\n", line);
		free(line);
	}
	close(fd);
	return (0);
}
 */