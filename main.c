#include "minishell.h"

/**
 * @brief  I guess print the stupid prompt with the HOME dir? or working dir
 * @note   if the working dir is home do I displaey ~ ??? fuck no
 * @retval None
 */
void	prompt()
{
	char buff[1024];
	char *wd;

	wd = getcwd(buff, 1024);
	putstr("\e[1m\e[38;5;14m[");
	putstr("\e[38;5;205m");
	putstr(wd);
	putstr("\e[38;5;14m] ");
	putstr("\e[38;5;226m$ \e[0m");
}

/**
 * @brief  get the stupid stream of commands
 * @note  *stream: size is 1, reallocate it if necessary
 * @retval None
 */
char	*read_stream(void)
{
	char	*istream;
	int		ret;
	char 	c;
	int		n;
	int		i;

	istream = (char *)malloc(STREAM_SIZE * sizeof(char));
	n = 1;
	i = 0;
	while ((ret = read(0, &c, 1)) && c != '\n')
	{
		*(istream + i) = c;
		istream = retarded_realloc(istream, n, n+1);
		i++;
		n++;
	}
	*(istream + i) = 0;
	if (ret == 0)
		exit(3);
	return (istream);
}

/**
 * @brief  I guess fucking split the stream, kill me
 * @note   
 * @param  istream: fetched stream
 * @retval split istream into args to execute later
 */
char	**split_stream(char *istream)
{
	char	**args;

	args = ft_split(istream, ' ');
	putstr(args[0]);
	putstr(args[1]);
	return (args);
}

int			found(char *path)
{
	char	*absolute_path;
	int		fd;

	if (!(absolute_path = ft_strjoin(path, "/brew")))
		return (0);
	if ((fd = open(absolute_path, O_RDONLY)) == -1)
		return (-1);
 	return (1);
}

/**
 * @brief  check if cmd is in path
 * @note   
 * @retval 
 */
t_status	check_path()
{
	char		*path;
	char		**dirs;
	int			i;
	t_status	status;

	path = _getenv("PATH");
	dirs =  ft_split(path, ':');
	// while (dirs[i])
		// printf("%s\n", dirs[i++]);
	i = 0;
	while (dirs[i])
	{
		printf("%s\n", dirs[i]);
		if (found(dirs[i]) == 1)
			return (OK);
		i++;
	}
	return (KO);
}

/**
 * @brief  initialize env variables to get PATH, and I dk the rest yet.
 * @note   
 * @param  argc: dk yet
 * @param  *argv[]: dk yet
 * @param  *envp[]: need for stealing env
 * @retval 
 */
int		main(int argc, char *argv[], char *envp[])
{
	char			*istream;
	char			**args;
	t_status		status;

	steal_env(argc, argv, envp);
	status = OK;
	while (status == OK)
	{
		prompt();
		istream = read_stream();
		putstr(istream);
		if ((status = check_path()) == OK)
			printf("yay!");
		// args = split_stream(istream);
		// status = exec_stream();
		// free(istream);
		// free(args);
	}
}
