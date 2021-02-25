#include "charlib.h"

int     _hexvalue(int c)
{
   return ((c >= 'a' && c <= 'f')
	? c -'a' + 10
	: c >= 'A' && c <= 'F' ? c-'A'+10 : c - '0');
}
