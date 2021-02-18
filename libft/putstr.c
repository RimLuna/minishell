#include "libft.h"

void        putstr(char *s)
{
    write(1, s, ft_strlen(s));
}
