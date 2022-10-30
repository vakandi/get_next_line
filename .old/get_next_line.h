/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbousfir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 22:43:59 by wbousfir          #+#    #+#             */
/*   Updated: 2022/10/13 02:43:41 by wbousfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

//# define BUFFER_SIZE 150

void	ft_putstr(char *s);
void	ft_putnbr(int n);
int		ft_strlen(const char *str);
void	ft_putstr_fd(int fd, char *str);
void	ft_putchar(char c);
void	ft_putchar_fd(int fd, char c);
char	*get_next_line(int fd);
char	*ft_print_line(char *str, char *buf, int j, int i);
void	ft_free_buffer(char *buf, char *str);
char	*ft_get_line(char *str, char *buf, int i, int j, int fd);

#endif
