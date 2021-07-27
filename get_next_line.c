#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"

int	ft_return(int read_return_value, char *static_memory, char *buf)
{
	if (read_return_value < 0)
	{
		free(buf);
		return (-1);
	}
	if (read_return_value == 0 && !static_memory)
		return (0);
	return (1);
}

char	*ft_new_line(int i)

{
	char	*tmp;

	tmp = malloc(i + 1);
	return (tmp);
}

int	get_next_line(int fd, char **line)
{
	char		*buf;
	int			read_return_value;
	char		*line_pointer;
	static char	*statick_memory;

	read_return_value = 1;
	if (BUFFER_SIZE <= 0 || !line || fd < 0 )
		return (-1);
	buf = ft_new_line(BUFFER_SIZE);
	while (read_return_value)
	{
		read_return_value = read(fd, buf, BUFFER_SIZE);
		if (read_return_value < 0)
			return (ft_return(read_return_value, statick_memory, buf));
		buf[read_return_value] = '\0';
		statick_memory = ft_strjoin(statick_memory, buf);
		line_pointer = ft_strchr(statick_memory, '\n');
		if (line_pointer)
			break ;
	}
	*line = ft_line(statick_memory);
	statick_memory = ft_line_remainder(statick_memory, line_pointer);
	free (buf);
	return (ft_return(read_return_value, statick_memory, buf));
}
