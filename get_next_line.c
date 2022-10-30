/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbousfir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 23:58:14 by wbousfir          #+#    #+#             */
/*   Updated: 2022/10/31 00:14:59 by wbousfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_putstr(char *s)
{
	if (s == NULL)
	return ;
	write(1, s, ft_strlen(s));
}

char	*new_str(char *buf, char *str)
{
	int	j;
	char	*new;

	j = 0;
	if (check_newline(buf) == 0)
	{
		free(str);
		return (NULL);
	}
	while (buf[j])
	{
		if (buf[j++] == '\n')
			break ;
	}
	if (buf[j] == 0)
	{
		free(str);
		return (0);
	}
	new = ft_strdup(buf + j);
	free(str);
	return (new);
}

char	*new_buf(char *buf)
{
	int		len;
	int		i;
	char	*new;

	len = 0;
	i = 0;
	if (check_newline(buf) == 0)
		return (buf);
	while (buf[len] != '\n')
		len++;
	len++;
	new = (char *) malloc(len + 1);
	len = 0;
	while (buf[len] != '\n')
		new[i++] = buf[len++];
	new[i++] = '\n';
	new[i] = 0;
	free(buf);
	return (new);
}

char	*read_file(int fd, int *end)
{
	char	*readed;
	int		nb;
	char	*tmp;

	readed = (char *) malloc(BUFFER_SIZE + 1);
	nb = read(fd, readed, BUFFER_SIZE);
	if (nb <= 0)
	{
		*end = 10;
		free(readed);
		return (NULL);
	}
	if (nb < BUFFER_SIZE)
	{
		readed[nb] = 0;
		tmp = ft_strdup(readed);
		free(readed);
		return (tmp);
	}
	readed[BUFFER_SIZE] = '\0';
	return (readed);
}

char	*get_next_line(int fd)
{
	static char	*str;
	str = NULL;
	char		*buf;
	int			end;

	end = 0;
	if (fd < 0)
		return (NULL);
	if (str)
		buf = ft_strdup(str);
	else
		buf = read_file(fd, &end);
	while (fd >= 0)
	{
		if (check_newline(buf) || end)
		{
			str = new_str(buf, str);
			return (new_buf(buf));
		}
		buf = ft_strjoin(buf, read_file(fd, &end));
	}
	return (NULL);
}


int	main(void)
{
	int	fd;

	fd = open("test/test.txt", O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("open() failed");
		return (1);
	}
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	if (close(fd) == -1)
	{
		ft_putstr("close() failed");
		return (1);
	}
	return (0);
	}
