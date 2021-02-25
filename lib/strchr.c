#include "strlib.h"

char *
_strchr(s, c)
const char *s;
int c;
{
	int				i;
	unsigned char	ch;

	i = 0;
	ch = (unsigned char)c;
	if (ch == '\0')
	{
		while (s[i] != '\0')
			i++;
		return (char*)(s + i);
	}
	while (s[i] != '\0')
	{
		if (s[i] == ch)
			return (char*)(s + i);
		i++;
	}
	return (NULL);
}
