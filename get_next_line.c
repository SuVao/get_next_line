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

static char	*get_line(char *str)
{
	char	*line;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	line = ft_substr(str, 0, i);
	return (line);
}

char	*get_rest(char *s)
{
	int	i;
	int len;
	char *s2;

	i = 0;
	while (s[i] != '\n' && s[i])
		i++;
	len = ft_strlen(s) - i;
	s2 = malloc(sizeof(char *) * len + 1);
	if (!s2)
		return (NULL);
	s2 = ft_substr(s, i, len);
	free (s);
	return (s2);
}

char	*get_next_line(int fd)
{
	static char	*ori_str;
	char		*final_boss;
	char		*rest_of_chars;
	int			i;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	ori_str = malloc(sizeof(char *) * (BUFFER_SIZE + 1));
	if (!ori_str)
		return (NULL);
	i = 1;
	while (!ft_strchr(ori_str, '\n') && i > 0)
	{
		i = read(fd, ori_str, BUFFER_SIZE);
		if (i < 0)
		{
			free (ori_str);
			return (NULL);
		}
		ori_str[BUFFER_SIZE] = '\0';
		final_boss = get_line(ori_str);
		rest_of_chars = get_rest(ori_str);
		final_boss = ft_strjoin(final_boss, rest_of_chars);
		free (rest_of_chars);
	}
	return (final_boss);
}

/* char	*get_next_line(int fd)
{
	static char	*rest;
	char		*buffer;
	char		*temp;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(buffer, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		if (!buffer)
			buffer = ft_strdup(temp);
		else
			buffer = 
		rest = get_line(buffer);
		temp = rest;
		free(rest);
		rest = temp;
	}
	free (buffer);
	return (get_line(rest));
} */

int	main()
{
	int fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
		printf("linha: %s \n", line++);
	close(fd);
	return (0);
}