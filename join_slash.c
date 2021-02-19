#include "minishell.h"

char    *join_slash(char *s1, char *s2)
{
    char    *tmp;

    if (!s2 || !s2)
        return (NULL);
    if (!ends_with(s1, "/"))
	{
		if (s2[0] == '/')
            return (ft_strjoin(s1, s2));
        else
        {
            tmp = ft_strjoin(s1, "/");
            printf("|%s| |%s| |%s| |%s|\n", s1, s2, tmp, ft_strjoin(tmp, s2));
            return (ft_strjoin(tmp, s2));
        }	
	}
    else
    {
        if (s2[0] == '/')
            return (ft_strjoin(s1, s2 + 1));
        else
            return (ft_strjoin(s1, s2));
    }
}
