/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pesilva- <pesilva-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 08:56:31 by pesilva-          #+#    #+#             */
/*   Updated: 2024/04/25 08:56:31 by pesilva-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*str3;
	char	*ptr3;
	char	*ptr1;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	str3 = malloc(sizeof(*str3) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str3)
	{
		free (s1);
		return (NULL);
	}
	ptr3 = str3;
    ptr1 = s1;
    i = 0;
    j = 0;
	while (ptr1[j])
		ptr3[i++] = ptr1[j++];
	j = 0;
    while (s2[j])
		ptr3[i++] = s2[j++];
	ptr3[i] = '\0';
	free (s1);
	return (&str3[i]);
}

char	*ft_strdup(const char *s1)
{
    char	*str;
    unsigned int	i;

    str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
    if (!str)
        return (NULL);
    i = 0;
    while (s1[i])
    {
        str[i] = s1[i];
        i++;
    }
    str[i] = '\0';
    return (str);
}

char	*ft_strchr(const char *s, int c)
{
    if (!s)
		return (NULL);
    while (*s)
    {
        if (*s == (char)c)
            return ((char *)s);
        s++;
    }
    if (*s == (char)c)
        return ((char *)s);
    return (NULL);
}

size_t  ft_strlen(const char *s)
{
    size_t  i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, unsigned int len)
{
    char	*str;
    unsigned int	i;

    if (!s)
        return (NULL);
    if (start > ft_strlen(s))
        return (ft_strdup(""));
    str = (char *)malloc(sizeof(char) * (len + 1));
    if (!str)
        return (NULL);
    i = 0;
    while (s[start] && i < len)
    {
        str[i] = s[start];
        i++;
        start++;
    }
    str[i] = '\0';
    return (str);
}
