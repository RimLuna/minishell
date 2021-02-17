#include "minishell.h"

char		**g_env_var;

/**
 * @brief  len of stolen envp variable
 * @note   
 * @param  *envp[]: 
 * @retval 
 */
int		envp_len(char *envp[])
{
	int		len;

	len = 0;
	while (envp[len])
		len++;
	return (len);
}

/**
 * @brief  I guess I need to set the env variables first
 * @note   I don't fucking know how to
 * @param  ac: 
 * @param  **av: 
 * @param  **envp: I know this is what i will fucking copy, cuz where else will I get them
 * @retval None
 */
void	steal_env(int argc, char *argv[], char *envp[])
{
	int		i;

	i = 0;
	g_env_var = (char **)malloc((envp_len(envp) + 1) * sizeof(char *));
	while (envp[i])
	{
		if (!(g_env_var[i] = ft_strdup(envp[i])))
			exit(-1);
		i++;
	}
}

/**
 * @brief  get shit after colon of env variable, i need ft_split and ft_strcmp
 * @note   
 * @param  *env_var: 
 * @retval 
 */
char	*_getenv(char *env_var)
{
	int		i;
	int		j;
	char	*after_colon;
	char	**tokens;

	i = 0;
	while (g_env_var[i])
	{
		if ((tokens = ft_split(g_env_var[i], '=')))
			if (ft_strcmp(env_var, tokens[0]) == 0)
				return (tokens[1]);
		i++;
	}
	return (after_colon);
}

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
	printf("\x1B[31m[");
	printf("\x1B[32m%s", wd);
	printf("\x1B[31m]\n");
	printf("\x1B[33m$ ");
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
	char		*buffer;

	steal_env(argc, argv, envp);
	prompt();
}
