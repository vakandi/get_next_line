#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*save;
	char		*buf;
	ssize_t		x;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd == 1 || fd == 2)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while (!ft_strchr(save, '\n'))
	{
		x = read(fd, buf, BUFFER_SIZE);
		if (x <= 0)
			break ;
		save = ft_strjoin(save, buf, x);
	}
	free(buf);
	if (ft_strlen(save) > 0 && x >= 0)
	{
		buf = nwline(save);
		save = cutline(save);
		return (buf);
	}
	free(save);
	return (save = NULL);
}
