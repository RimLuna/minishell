#include "minishell.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*string;
	int		lend;
	int		lens;

	if (!s1 || !s2)
		return (NULL);
	lend = ft_strlen(s1);
	lens = ft_strlen(s2);
	string = (char*)malloc((lend + lens + 1) * sizeof(char));
	if (!string)
		return (NULL);
	ft_memmove(string, s1, lens + lend);
	ft_memmove(string + lend, s2, lens);
	*(string + (lens + lend)) = '\0';
	return (string);
}
