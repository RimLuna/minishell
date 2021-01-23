#include "minishell.h"

char	*ft_readline()
{
	
	return (NULL);
}

void	start()
{
	char	*line;

	while (TRUE)
	{
		write(1, PROMPT, 2);
		fflush(stdout);
		if (!(line = ft_readline()))
			return ;
	}
}

int		main()
{
	start();
	return (0);
}
