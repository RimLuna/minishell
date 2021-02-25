#ifndef BUILTINS_H
# define BUILTINS_H

# include <stdlib.h>

char **
(*bf(int i))(char **args, char **env);

char	**_cd(char **args, char **env);

char	**_env(char **args, char **env);

char	**_pwd(char **args, char **env);

char	**_echo(char **args, char **env);

char	**_unset(char **args, char **env);

char	**_export(char **args, char **env);

char	**_exit2(char **args, char **env);

char	**_dot(char **args, char **env);
#endif
