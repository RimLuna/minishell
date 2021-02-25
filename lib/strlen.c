#include "strlib.h"

int
_strlen(s)
const char *s;
{
    int     i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}
