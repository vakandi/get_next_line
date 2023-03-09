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

char	*ft_strjoin(char *save, char *buf, int count)
{
	char	*p;
	int		x;
	int		y;

		buf[count] = 0;
	x = 0;
	y = 0;
	p = malloc((ft_strlen(save) + ft_strlen(buf) + 1) * sizeof(char));
	if (!p)
		return (NULL);
	if (save)
	{
		while (save[x])
		{
		p[x] = save[x];
		x++;
		}
	}
	while (buf[y])
		p[x++] = buf[y++];
	p[x] = '\0';
	if (save)
		free(save);
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

char	*nwline(char *save)
{
	char	*line;
	int		x;

	x = 0;
	while (save[x] && save[x] != '\n')
		x++;
	if (save[x] == '\n')
		x++;
	line = malloc((x + 1) * sizeof(char));
	if (!line)
		return (NULL);
	x = 0;
	while (save[x] && save[x] != '\n')
	{
		line[x] = save[x];
		x++;
	}
	if (save[x] == '\n')
	{
		line[x] = save[x];
		x++;
	}
	line[x] = '\0';
	return (line);
}

char	*cutline(char *save)
{
	char	*cut;
	int		x;
	int		y;

	y = 0;
	x = 0;
	while (save[x] && save[x] != '\n')
		x++;
	if (save[x] == '\n')
		x++;
	cut = malloc((ft_strlen(save) - x) + 1 * sizeof(char));
	if (!cut)
		return (NULL);
	while (save[x])
		cut[y++] = save[x++];
	cut[y] = '\0';
	if (save)
		free(save);
	return (cut);
}
