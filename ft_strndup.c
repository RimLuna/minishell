#include "minishell.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char *new;

	if (!(new = (char *)malloc((n + 1) * sizeof(char))))
		return (NULL);
	ft_strlcpy(new, s1, n + 1);
	return (new);
}
