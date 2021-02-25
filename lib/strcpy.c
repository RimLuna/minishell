#include "strlib.h"

char	*
_strcpy(dst, src)
char *dst;
char *src;
{
	int		i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i += 1;
	}
	dst[i] = '\0';
	return (dst);
}
