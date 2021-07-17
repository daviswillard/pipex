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

static char	*flnm(char **env, char *filename)
{
	int		check;
	int		index;
	char	*temp;

	check = 0;
	index = 0;
	temp = ft_strjoin(env[index], filename);
	while (!check)
	{
		if (!temp)
			return (NULL);
		if (!access(temp, F_OK))
			check = 1;
		if (!check)
		{
			free(temp);
			temp = ft_strjoin(env[index], filename);
		}
	}
	return (temp);
}

char	**get_args(char **argv)
{

}

int	pipex(char **argv, char **envp)
{
	char	*argd;
	char	**env;
	pid_t	pid;
	char	**args;
	char	*filename;

	filename = "";
	argd = rd_arg1(argv);
	env = get_env(envp);
	args = get_args(argv);
	pid = fork();
	if (pid == 0)
	{
		filename = flnm(env, filename);
		execve(filename, args, env);
	}
	else
		wait(NULL);
	if (argd)
		ft_putstr_fd(argd, 0);
	free(argd);
	return (0);
}
