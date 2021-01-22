#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char	*get_raw(char *s)
{
	int		i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	s[i] = 0;
	return (s);
}

void	show_prompt()
{
	char		*path;
    const char	*paths[100];
	int			i;
    char		*token;
	char		command[1024];
	char		*raw_command;

	path = getenv("PATH");
    token = strtok(path, ":");
    paths[0] = token;

    i = 1;
    while (token != NULL)
	{
        token = strtok(NULL, ":");
        paths[i] = token;
        i++;
    }
	write(1, "$ ", 2);
	read(1, command, 1024);
	raw_command = get_raw(command);
	if (exists(absolute_path))
		execve(absolute_path);
	printf("%s", command);
}

int		main(void)
{
	show_prompt();
}
