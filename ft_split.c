#include "minishell.h"

static int		ft_wc(const char *s, char c)
{
	size_t i;
	size_t count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] && (s[i] != c))
			i++;
	}
	return (count);
}

static void		ft_free_me(char ***array, int lignes)
{
	int i;

	i = 0;
	while (i++ < lignes)
		free(*array[i]);
	free(*array);
	*array = NULL;
}

char			**ft_split(const char *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	n_words;
	char	**words;

	i = 0;
	n_words = 0;
	if (!s || (!(words = (char **)malloc(sizeof(char *) * (ft_wc(s, c) + 1)))))
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > j)
		{
			if ((words[n_words] = ft_strndup(s + j, i - j)) == NULL)
				ft_free_me(&words, ft_wc(s, c));
			n_words++;
		}
	}
	words[n_words] = NULL;
	return (words);
}
