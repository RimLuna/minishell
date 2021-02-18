#include "minishell.h"

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
