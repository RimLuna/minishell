#include "shell.h"

void
envcpy(env)
char *** env;
{
	int		nenv;

	nenv = -1;
	while (environ[++nenv])
		;
	(*env) = (char **)_memalloc(nenv * sizeof(char *));
	nenv = -1;
	while (environ[++nenv])
		(*env)[nenv] = _strdup(environ[nenv]);
	(*env)[nenv] = NULL;
}

/**
 * @brief  need to allocate env for unset, cant just point to it
 * @note   copy env from environ
 * @retval 
 */
int
main (ac, av, envp)
int		ac;
char	**av;
char	**envp;
{
	char	**env;
	int		i;

	// env = environ;
	envcpy(&env);
	// i = -1;
	// while (env[++i])
	// {
	// 	_puts(env[i]);
	// 	_puts("\n");
	// }
	return (_shell(env));

	// env = _getenv(env, "PATH");
	// _puts(env);
	// _puts(envp[0]);

	(void)ac;
}
