#include "pipex.h"

char	**get_env(char **envp)
{
	int		ind_glob;
	char	*path;
	char	**split;

	ind_glob = 0;
	path = ft_strnstr(envp[ind_glob++], "PATH", 4);
	while (!path && envp[ind_glob])
		path = ft_strnstr(envp[ind_glob++], "PATH", 4);
	if (!path)
		return (NULL);
	path = ft_strchr(path, '/');
	split = ft_split(path, ':');
	if (!split)
		exit (-1);
	return (split);
}

static void	*fullclean(int counter, char **ret)
{
	int		clcounter;

	clcounter = 0;
	while (clcounter != counter)
	{
		free(ret[clcounter]);
		clcounter++;
	}
	free(ret);
	return (NULL);
}

static int	skip(char **hold)
{
	if (**hold == '\0')
		return (1);
	while (**hold == ' ')
		(*hold)++;
	while (**hold != ' ' && **hold != '\0')
		(*hold)++;
	if (**hold == ' ')
		*(*hold)++ = '\0';
	return (0);
}

char	**get_args(char *argv)
{
	char	*hold;
	char	**ret;
	int		counter;

	counter = 0;
	hold = argv;
	ret = malloc(sizeof(char **) * 2);
	if (!ret)
		return (NULL);
	while (!skip(&hold))
	{
		ret[counter] = ft_strdup(argv);
		if (!ret[counter])
			return (fullclean(counter, ret));
		argv = hold;
		counter++;
	}
	ret[counter] = NULL;
	return (ret);
}
