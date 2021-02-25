#ifndef STRLIB_H
# define STRLIB_H

# include <unistd.h>
# include <stdlib.h>
# include "charlib.h"
# define BUFFER_SIZE 1024


char *
_strchr(const char *s, int c);

char	*
_strcpy(char *dst, char *src);

int
_strcmp(const char *s1, const char *s2);

char *
_strnew(size_t size);

void
_bzero(void *s, size_t n);

void *
_memset(void *b, int c, size_t len);

void *
_memalloc(size_t size);

void
_puts (const char *s);

int
_strlen(const char *s);

int
_strncmp(const char	*s1, const char	*s2, size_t	n);

char **
_strtok(char *s, char *delim);

char *
_readline(void);

char *
_strjoin(char *s1, char *s2);

char *
_strdup(char *str);

int
get_next_line(int fd, char **line);

#endif
