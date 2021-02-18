#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

/**
 * @brief  all libft bullshit
 */
size_t	        ft_strlen(const char *s);
char	        *ft_strdup(const char *s1);
void	        *ft_memcpy(void *dst, const void *src, size_t n);
char	        *ft_strndup(const char *s1, size_t n);
int             ft_strcmp(char *s1, char *s2);
char			**ft_split(const char *s, char c);
size_t      	ft_strlcpy(char *dst, const char *src, size_t size);
char	        *ft_strjoin(char const *s1, char const *s2);
void	        *ft_memmove(void *dst, const void *src, size_t len);
void            *retarded_realloc(void *p0, size_t size0, size_t size1);
void            putstr(char *s);
#endif
