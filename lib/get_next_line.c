#include "strlib.h"

static int		ft_indexof(str, c)
char	*str;
char	c;
{
	int	i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char			*ft_substr(str, start, len)
char	*str;
int		start;
int		len;
{
	int		size;
	char	*substr;
	int		i;

	size = (start + len > _strlen(str)) ? _strlen(str) - start : len;
	if (!(substr = (char *)malloc((size + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (i < size)
	{
		substr[i] = str[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

static int		read_line(fd, str)
int		fd;
char	**str;
{
	int		ret;
	char	*buf;
	char	*tmp;

	if (!(buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char))))
		return (-1);
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (*str)
		{
			tmp = *str;
			*str = _strjoin(*str, buf);
			free(tmp);
		}
		else
			*str = _strdup(buf);
		if (ft_indexof(*str, '\n') > 0)
			break ;
	}
	free(buf);
	return (ret);
}

int				get_next_line(fd, line)
int		fd;
char	**line;
{
	static char		*str;
	int				i;
	char			*tmp;

	if (fd < 0 || !line || read(fd, str, 0) < 0)
		return (-1);
	if (!(ft_indexof(str, '\n') > 0))
		read_line(fd, &str);
	if (!str)
	{
		*line = _strdup("");
		return (0);
	}
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	*line = ft_substr(str, 0, i);
	tmp = (str[i] == '\n') ? _strdup(str + i + 1) : NULL;
	free(str);
	str = tmp;
	if (!str)
		return (0);
	return (1);
}
