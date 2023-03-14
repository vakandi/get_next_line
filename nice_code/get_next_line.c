/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbousfir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 22:11:08 by wbousfir          #+#    #+#             */
/*   Updated: 2023/03/10 19:59:19 by wbousfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*saved;
	char		*buf;
	int			x;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd == 1 || fd == 2)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while (return_found_char(saved, '\n') == 0)
	{
		x = read(fd, buf, BUFFER_SIZE);
		if (x <= 0)
			break ;
		saved = ft_strjoin(saved, buf, x);
	}
	free(buf);
	if (ft_strlen(saved) > 0 && x >= 0)
	{
		buf = return_full_line(saved);
		saved = return_line_after_newline(saved);
		return (buf);
	}
	free(saved);
	return (saved = NULL);
}
/*
int	main(void)
{
	int	fd;
	char *p;
	int x = 0;
	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		write(1, "open() failed", 13);
		return (1);
	}
	printf("%s\n", p);
	//while(x < 100)
//	{
//		p = get_next_line(fd);
//		printf("%s\n", p);
//		free(p);
//		x++;
//	}
	while(1);
	if (close(fd) == -1)
	{
		write(1, "close() failed", 13);
		return (1);
	}
	return (0);
}

*/
