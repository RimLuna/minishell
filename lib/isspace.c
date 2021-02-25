#include "charlib.h"

int     _isspace(int c)
{
    return (c == ' ' || c == '\t' || c == '\n' || c == '\f' || c == '\r');
}
