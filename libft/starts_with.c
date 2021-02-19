#include "libft.h"

int		starts_with(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s2[i])
    {
		if (s1[i] != s2[i])
			return (0);
        i++;
    }
	return (1);
}
