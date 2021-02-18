#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include "libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define OK 0
# define KO 1
# define STREAM_SIZE 1

typedef int t_status;
char		**g_env_var;

/**
 * @brief  minishell bullshit
 */
int	        	main(int argc, char *argv[], char *envp[]);
void	        prompt();
char	        *_getenv(char *env_var);
void	        steal_env(int argc, char *argv[], char *envp[]);
int		        envp_len(char *envp[]);

#endif