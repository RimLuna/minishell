#include "minishell.h"

size_t	ft_strlen(const char *s)
{
	const char *p;

	p = s;
	while (*p)
		p++;
	return (p - s);
}
