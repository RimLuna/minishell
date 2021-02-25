#include "strlib.h"

char	*_strdup(str)
char	*str;
{
	char	*dup;
	int		i;

	if (!(dup = (char *)malloc((_strlen(str) + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (str[i])
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
