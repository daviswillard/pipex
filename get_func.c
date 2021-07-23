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
