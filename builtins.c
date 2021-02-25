#include "shell.h"

char **
(*bf(int i))(char **args, char **env)
{
	char ** (*bf[9])(char **args, char **env);

	bf[0] = &_env;
	bf[1] = &_cd;
	bf[2] = &_pwd;
	bf[3] = &_export;
	bf[4] = &_echo;
	bf[5] = &_unset;
	bf[6] = &_dot;
	bf[7] = &_exit2;
	// bf[8] = &_alias;
	return (bf[i]);
}
