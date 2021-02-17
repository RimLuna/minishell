#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# define TRUE 1
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

/**
 * @brief  minishell bullshit
 */
int	        	main(int argc, char *argv[], char *envp[]);

#endif