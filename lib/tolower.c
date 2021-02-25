#include "charlib.h"

int     _tolower(int c)
{
    return ((c >= 'A' && c <= 'Z') ? c - 'A' + 'a' : c);
}
