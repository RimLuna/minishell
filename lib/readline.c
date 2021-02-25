#include "strlib.h"

char		*_readline(void)
{
	char	*line;

	line = NULL;
	get_next_line(0, &line);
	return (line);
}
