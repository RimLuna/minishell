#ifndef SHELL_H
# define SHELL_H

# include "lib/strlib.h"
# include <unistd.h>

# define BUFFER_SIZE 1024
# define PROMPT "$ "
# include "builtins.h"

#include <sys/types.h>
#include <sys/stat.h>

# define HOME "/Users/rbougssi"

extern char **environ;
extern char *builtins[9];

int
is_option(char *s, int c);

void
print_prompt(char **env);

char *
_getenv(char **env, const char *name);

char **
execute_cmd(char **args, char **env);

int
execute_cmds(char **cmd, char **env);

int
_shell(char **env);

void
envcpy(char ***env);
#endif