/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesilva- <pesilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:39:28 by pesilva-          #+#    #+#             */
/*   Updated: 2024/04/29 11:39:28 by pesilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_newl(int fd, char *s)
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
	static char	*str_file[MAX_FILES];
	char		*final_boss2;
	char		*paparestos;
	int			i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	str_file[fd] = get_newl(fd, str_file[fd]);
	if (!str_file[fd])
		return (NULL);
	while (str_file[fd][i] != '\n' && str_file[fd][i])
		i++;
	if (str_file[fd][i] == '\n')
		i++;
	final_boss2 = ft_substr(str_file[fd], 0, i);
	paparestos = ft_substr(str_file[fd], i, ft_strlen(str_file[fd]) - i);
	free (str_file[fd]);
	str_file[fd] = paparestos;
	return (final_boss2);
}

/* int	main(void)
{
	int		fd1, fd2;
	char	*line;

	fd1 = open("test.txt", O_RDONLY);
	if (fd1 < 0)
		return (1);
	fd2 = open("test1.txt", O_RDONLY);
	if (fd2 < 0)
	{
		close(fd1);
		return (1);
	}
	printf("Contents of test.txt:\n");
	while ((line = get_next_line_bonus(fd1)) != NULL)
	{
		printf("%s\n", line);
		free(line);
	}
	close(fd1);
	printf("\nContents of test1.txt:\n");
	while ((line = get_next_line_bonus(fd2)) != NULL)
	{
		printf("%s\n", line);
		free(line);
	}
	close(fd2);
	return (0);
}
 */
/* int main()
{
    int     fd, i;
    char    *line;

    fd = open("test.txt", O_RDWR);
    i = 1;
    line = get_next_line(fd);
    printf("%s\n", line);
    write(1, "endline", 7);
    free(line);
    line = get_next_line(fd);
    printf("%s\n", line);
    write(1, "endline", 7);
    free(line);
    while ((line = get_next_line(fd)))
    {
        printf("LINE %d:\n", i);
        printf("%s\n", line);
        free(line);
        i++;
    }
    close(fd);
} */
