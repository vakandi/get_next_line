/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbousfir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 22:11:15 by wbousfir          #+#    #+#             */
/*   Updated: 2023/03/09 22:11:18 by wbousfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *saved, char *buf, int count)
{
	char	*p;
	int		x;
	int		y;

	buf[count] = 0;
	x = 0;
	y = 0;
	p = malloc((ft_strlen(saved) + ft_strlen(buf) + 1) * sizeof(char));
	if (!p)
		return (NULL);
	if (saved)
	{
		while (saved[x])
		{
		p[x] = saved[x];
		x++;
		}
	}
	while (buf[y])
		p[x++] = buf[y++];
	p[x] = '\0';
	if (saved)
		free(saved);
	return (p);
}

int	ft_strlen(char *str)
{
	int	x;

	x = 0;
	if (!str)
		return (0);
	while (str[x] != '\0')
		x++;
	return (x);
}

// This function searches for the first occurrence of a character in a string.
// If the character is found, it returns a pointer to the character in the string.
// If the character is not found, it returns NULL.

char *ft_strchr(char *s, int c)
{
    // Initialize a variable x to 0.
    int x = 0;

    // Check if the string is NULL, if so, return NULL.
    if (s == NULL)
    {
        return (NULL);
    }

    // Loop through the string until the end is reached.
    while (s[x] != '\0')
    {
        // If the current character in the string is equal to the target character,
        // return a pointer to the current character in the string.
        if (s[x] == c)
        {
            return (&s[x]);
        }

        // Increment the index variable x.
        x++;
    }

    // If the target character is not found in the string, return NULL.
    return (NULL);
}

/*
char	*ft_strchr(char *s, int c)
{
	int	x;

	x = 0;
	if (!s)
		return (NULL);
	while (s[x] != '\0')
	{
		if (s[x] == c)
			return (s + x);
		x++;
	}
	return (NULL);
}
*/
char	*return_full_line(char *saved)
{
	char	*line;
	int		x;

	x = 0;
	while (saved[x] && saved[x] != '\n')
		x++;
	if (saved[x] == '\n')
		x++;
	line = malloc((x + 1) * sizeof(char));
	if (!line)
		return (NULL);
	x = 0;
	while (saved[x] && saved[x] != '\n')
	{
		line[x] = saved[x];
		x++;
	}
	if (saved[x] == '\n')
	{
		line[x] = saved[x];
		x++;
	}
	line[x] = '\0';
	return (line);
}

char	*return_line_after_newline(char *saved)
{
	char	*cut;
	int		x;
	int		y;

	y = 0;
	x = 0;
	while (saved[x] && saved[x] != '\n')
		x++;
	if (saved[x] == '\n')
		x++;
	cut = malloc((ft_strlen(saved) - x) + 1 * sizeof(char));
	if (!cut)
		return (NULL);
	while (saved[x])
		cut[y++] = saved[x++];
	cut[y] = '\0';
	if (saved)
		free(saved);
	return (cut);
}
