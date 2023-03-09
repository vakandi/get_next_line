/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzakkabi <wzakkabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 02:38:52 by majjig            #+#    #+#             */
/*   Updated: 2023/03/09 19:42:48 by wzakkabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_SIZE
# define BUFFER_SIZE
#endif

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
/* INCLUDES */
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>

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
