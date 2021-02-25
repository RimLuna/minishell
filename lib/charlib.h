#ifndef CHARLIB_H
# define CHARLIB_H

/**
 * @brief  char lib for functions that should be fucking macros but we're not allowed to use parameter macros
 * @note   kill me, gcc -c *.c; gcc -shared -o charlib.so *.c
 * @param  c: 
 * @retval 
 */
int     _isspace(int c);
int		_isprint(int c);
int     _toupper(int c);
int     _tolower(int c);
int		_isxdigit(int c);
int		_isupper(int c);
int     _isspace(int c);
int		_isprint(int c);
int     _isoctal(int c);
int		_islower(int c);
int		_isdigit(int c);
int		_isalpha(int c);
int		_isalnum(int c);
int     _hexvalue(int c);
#endif
