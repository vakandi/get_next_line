/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbousfir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 21:55:29 by wbousfir          #+#    #+#             */
/*   Updated: 2022/10/13 23:30:05 by wbousfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_putstr(char *s)
{
	if (s == NULL)
		return ;
	write(1, s, ft_strlen(s));
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	*ft_get_line(char *str, char *buf, int i, int j, int fd)
{
	int ret;

	ret = read(fd, buf, BUFFER_SIZE);
	while (buf[i] != '\0')
	{
		if (buf[i] != '\n')
			i++;
		else
		{
			while (j <= i)
			{
				str[j] = buf[j];
				printf("%c", buf[j]);
				j++;
			}
			str = (char *)malloc(sizeof(j + 1));
			if (str == NULL)
				return (NULL);
			ret = read(fd, buf, BUFFER_SIZE);
			i++;
			return(str);
		}
		i++;
	}
	return(0);
}
/*
char	*ft_get_line(char *str, char *buf, int i, int j, int fd)
{
	int ret;
 
	ret = read(fd, buf, BUFFER_SIZE);
	while (buf[i] != '\0')
	{
		if (buf[i] != '\n')
			i++;
		else
		{
			while (j <= i)
			{
				str[j] = buf[j];
				printf("%c", buf[j]);
				j++;
			}
		///	str = malloc((int)j + 1) * sizeof(char);
			str = (char *)malloc(sizeof(*str) * (j + 1));
			if (str == NULL)
				return (NULL);
			ret = read(fd, buf, BUFFER_SIZE);
			i++;
			return(str);
		}
		i++;
	}
	return(0);
}*/
/*
char	*ft_print_line(char *str, char *buf, int j, int i)
{
	while (buf[i] != '\n')
	{
		if (buf[i] != '\n')
			i++;
		else
		{
			while (j <= i)
			{
				str[j] = buf[j];
				j++;
			}
			i++;
			return (str);
		}
		i++;
	}
	return (0);
}*/
