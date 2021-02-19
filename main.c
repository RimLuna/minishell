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
void	read_stream(char **istream)
{
	int		ret;
	char 	c;
	int		n;
	int		i;

	*istream = (char *)malloc(STREAM_SIZE * sizeof(char));
	n = 1;
	i = 0;
	while ((ret = read(0, &c, 1)) && c != '\n')
	{
		*(*istream + i) = c;
		*istream = retarded_realloc(*istream, n, n+1);
		i++;
		n++;
	}
	*(*istream + i) = 0;
	if (ret == 0)
		exit(3);
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
 * @brief  run command, dk why I didnt just execute it in that function
 * @note   
 * @param  *abs_path: 
 * @retval 
 */
int 	run(char *abs_path)
{
	pid_t	pid;

	pid = fork();
	if (!pid)
		execve(abs_path, NULL, g_env_var);
	else if (pid < 0)
	{
		putstr("Failed to fork..");
		return (-1);
	}
	wait(&pid);
	return (OK);
}

/**
 * @brief  executes shit, checks if we have permission to or not.
 * @note   
 * @param  *abs_path: absolute path to command, no args
 * @param  statbuf: stat structure filled by lstat
 * mode_t    st_mode; File type and mode
 * 
 * @retval 
 */
int		execute(char *abs_path, struct stat statbuf)
{
	printf("\nABSSSSS :::::: %s\n\n", abs_path);
	if (statbuf.st_mode)
		return (run(abs_path));
	else
	{
		putstr("Permission denied.");
		return (KO);
	}
}

/**
 * @brief  check if cmd is in path, if it is, executes it, sinon, not yet
 * @note   
 * @retval 
 */
int		check_in_path(char *istream)
{
	char		**paths;
	int			i;
	int			status;
	char		*abs_path;
	struct stat statbuf;

	paths = ft_split(_getenv("PATH"), ':');

	// while (dirs[i])
		// printf("%s\n", dirs[i++]);
	// printf("hello\n");
	i = 0;
	while (paths && paths[i])
	{
		if (starts_with(istream, paths[i]))
			abs_path = ft_strdup(istream);
		else
		{
			abs_path = join_slash(paths[i], istream);
			putstr(abs_path);
		}
		if (lstat(abs_path, &statbuf) != -1)
			return (execute(abs_path, statbuf));
		i++;
	}
	putstr("Command not found\n");
	return (0);
}

/**
 * @brief  this tries to execute the input stream
 * @note   calls to check if istream is in path or not
 * if yes, then already executed that shit, returned OK
 * @param  *istream: fucking input stream
 * @retval 
 */
int 	execute_stream(char *istream)
{
	return (check_in_path(istream));
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
	int		status;

	steal_env(argc, argv, envp);
	status = OK;
	while (status == OK)
	{
		prompt();
		read_stream(&istream);
		status = execute_stream(istream);
		// args = split_stream(istream);
		// status = exec_stream();
		// free(istream);
		// free(args);
	}
}
