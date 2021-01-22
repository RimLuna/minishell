#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct	s_dir
{
	char		*env_path;
	int			n;
	char		**paths;
}				t_dir;

void	show_prompt()
{
	char		command[101];
	char		*full_path;
	int			i;

	full_path = getenv("PATH");

	write(1, "$ ", 2);
	read(1, command, 100);
	i = 0;
	while (full_path[i])
	{
		while (full_path[i] != ':')
			
	}
	if (execve())
}

int		main(void)
{
	show_prompt();
}
