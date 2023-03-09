#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100000000000
# endif

char	*get_next_line(int fd);
char	*nwline(char *p);
char	*cutline(char *p);
char	*ft_strchr(char *s, int c);
int		ft_strlen(char *p);
char	*ft_strjoin(char *save, char *buf, int count);

#endif
