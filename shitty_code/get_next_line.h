/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbousfir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 22:05:41 by wbousfir          #+#    #+#             */
/*   Updated: 2023/03/09 22:06:45 by wbousfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
/* INCLUDES */
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
//# define _BUFFER_SIZE_

/* PROTOTYPES */
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
int		is_nl(char *s);
char	*ft_strdup(char *src);
int		ft_strlen(char *str);
char	*new_line(char *line);
char	*new_str(char *line, char *remain);
char	*read_file(int fd, int *end);
#endif
