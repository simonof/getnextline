#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*tmp;
	int		i1;
	int		i2;

	i1 = ft_strlen(s1);
	i2 = ft_strlen(s2);
	tmp = malloc(sizeof(char) * (i1 +i2 + 1));
	if (!tmp)
		return (NULL);
	i1 = 0;
	i2 = 0;
	while (s1 && s1[i1])
	{
		tmp[i1] = s1[i1];
		i1++;
	}
	while (s2 && s2[i2])
	{
		tmp[i1 + i2] = s2[i2];
		i2++;
	}
	tmp[i1 + i2] = '\0';
	free (s1);
	return (tmp);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	chr;

	chr = c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == chr)
			return ((char *)s + i + 1);
		i++;
	}
	if (s[i] == chr)
		return ((char *)s + i + 1);
	return (0);
}

char	*ft_line(char *static_memory)
{
	char	*tmp;
	int		i;

	i = 0;
	while (static_memory[i] != '\0' && static_memory[i] !='\n')
		i++;
	tmp = malloc(sizeof(char) * i + 1);
	if (!tmp)
		return (NULL);
	i = 0;
	while (static_memory[i] != '\0' && static_memory[i] !='\n')
	{
		tmp[i] = static_memory[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	*ft_line_remainder(char *static_memory, char *ptr)
{
	char	*tmp;
	int		i;
	int		l;

	i = 0;
	l = 0;
	if (!static_memory)
		return (NULL);
	while (static_memory[i] != '\0' && static_memory[i] != '\n')
		i++;
	if (static_memory[i] == '\0')
	{
		free(static_memory);
		return (0);
	}
	tmp = malloc(sizeof(char) * (ft_strlen(static_memory) - i) + 1);
	if (!tmp)
		return (NULL);
	if (ptr)
		i++;
	while (static_memory[i] != '\0')
		tmp[l++] = static_memory[i++];
	free (static_memory);
	tmp[l] = '\0';
	return (tmp);
}
