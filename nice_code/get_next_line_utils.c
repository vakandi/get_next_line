/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbousfir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 22:11:15 by wbousfir          #+#    #+#             */
/*   Updated: 2023/03/10 19:42:30 by wbousfir         ###   ########.fr       */
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
	if (p == 0)
		return (NULL);
	if (saved != 0)
	{
		while (saved[x] != 0)
		{
			p[x] = saved[x];
			x++;
		}
	}
	while (buf[y] != 0)
		p[x++] = buf[y++];
	p[x] = '\0';
	if (saved != 0)
		free(saved);
	return (p);
}

int	ft_strlen(char *str)
{
	int	x;

	x = 0;
	if (str == 0)
		return (0);
	while (str[x] != '\0')
		x++;
	return (x);
}

char	*return_found_char(char *s, int c)
{
	int	x;

	x = 0;
	if (s == NULL)
	{
		return (NULL);
	}
	while (s[x] != '\0')
	{
		if (s[x] == c)
		{
			return (&s[x]);
		}
		x++;
	}
	return (NULL);
}

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
	if (line == 0)
		return (NULL);
	x = 0;
	while (saved[x] != 0 && saved[x] != '\n')
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
	if (cut == 0)
		return (NULL);
	while (saved[x] != 0)
		cut[y++] = saved[x++];
	cut[y] = '\0';
	if (saved != 0)
		free(saved);
	return (cut);
}
