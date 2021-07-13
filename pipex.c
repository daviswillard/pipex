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
	path += 5;
	split = ft_split(path, '/');
	if (!split)
		exit (-1);
	return (split);
}

int	pipex(char **argv, char **envp)
{
	char	*argd;
	char	**env;
	pid_t	pid;
	int		status;

	argd = rd_arg1(argv);
	env = get_env(envp);
	pid = fork();
	if (pid == 0)
		execve(argv[2], args, env);
	else
		wait(NULL);
	if (argd)
		ft_putstr_fd(argd, 0);
	free(argd);
	return (0);
}
