#include "charlib.h"

int     _toupper(int c)
{
    return ((c >= 'a' && c <= 'z') ? c - 'a' + 'A' : c);
}
