#include "strlib.h"

void
_puts (s)
const char    *s;
{
    write(1, s, _strlen(s));
}
