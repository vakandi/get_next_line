/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbousfir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 22:05:37 by wbousfir          #+#    #+#             */
/*   Updated: 2022/10/13 23:33:53 by wbousfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_putchar_fd(int fd, char c)
{
	write(fd, &c, 1);
}

void	ft_free_buffer(char *buf, char *str)
{
	free(str);
	free(buf);
}

char	*get_next_line(int fd)
{
	int		i;
	int		j;
	char	*buf = NULL;
	char	*str = NULL;

	i = 0;
	j = 0;
//	if (fd == -1)
//		return (0);
	ft_get_line(str, buf, j, i, fd);
//	printf("%s", ft_get_line(str, buf, j, i, fd));
	//ft_get_line(str, buf, j, i, fd);
	return (0);
	ft_free_buffer(buf, str);
}
/*
int	main(void)
{
	int	fd;

	fd = open("test/test.txt", O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("open() failed\n");
		return (1);
	}
	get_next_line(fd);
	if (close(fd) == -1)
	{
		ft_putstr("close() failed\n");
		return (1);
	}
	return (0);
}*/
