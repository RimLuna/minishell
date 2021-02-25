#include "shell.h"

void
print_prompt (env)
char **env;
{
	char		*pwd;

	pwd = NULL;
	pwd = _getenv(env, "PWD") ? _getenv(env, "PWD") : _strdup("makaynch PWD");
	_puts("\e[1m\e[38;5;14m[");
	_puts("\e[38;5;205m");
	_puts((!_strcmp(pwd, HOME) ? "~" : pwd));
	_puts("\e[38;5;14m] ");
	_puts("\e[38;5;226m$ \e[0m");
	// if (pwd)
	// 	free(pwd);
	(pwd ? free(pwd) : (void)0);
}

char *
_getenv(env, name)
char **env;
const char *name;
{
	const char	*np;
	char		**p;
	char		*c;
	int			len;
	int			*offset;

	if (name == '\0')
		return (NULL);
	np = name;
	while (*np && *np != '=')
		np++;
	len = np - name;
	p = env;
	while ((c = *p) != NULL)
	{
		if (_strncmp(c, name, len) == 0 && c[len] == '=')
		{
			offset = p - env;
			return (_strdup(c + len + 1));
		}
		p++;
	}
	return (NULL);
}

int
_shell(env)
char	**env;
{
	int		status;
	char	**cmds;
	char	*line;

	status = 1;
	while (status)
	{
		print_prompt(env);
		line = _readline();
		cmds = _strtok(line, ";");
		status = execute_cmds(cmds, env);
		free(cmds);
		free(line);
	}
	return (status);

}
