/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbousfir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 22:11:12 by wbousfir          #+#    #+#             */
/*   Updated: 2023/03/10 19:28:16 by wbousfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
//# include <stdio.h>
# include <stdio.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

char	*get_next_line(int fd);
char	*return_full_line(char *p);
char	*return_line_after_newline(char *p);
char	*return_found_char(char *s, int c);
int		ft_strlen(char *p);
char	*ft_strjoin(char *save, char *buf, int count);
void	ft_putstr(char *str);

#endif
