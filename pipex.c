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

static void	*fclean(int counter, char **ret)
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

char	**get_args(char **argv)
{
	char	*temp;
	char	*hold;
	char	**ret;
	int		counter;

	counter = 0;
	ret = malloc(sizeof(ret));
	hold = argv[2];
	temp = ft_strchr(hold, ' ');
	while (temp)
	{
		*temp++ = '\0';
		ret[counter] = ft_strdup(hold);
		if (!ret[counter])
			return (fclean(counter, ret));
		hold = temp;
		counter++;
		temp = ft_strchr(hold, ' ');
	}
	if (!counter)
		ret[counter++] = ft_strdup(hold);
	ret[counter] = NULL;
	if (!ret[counter - 1])
		return (fclean(counter, ret));
	return (ret);
}

int	pipex(char **argv, char **envp)
{
	char	*argd;
	char	**env;
	pid_t	pid;
	char	**args;
	char	*filename;

	argd = rd_arg1(argv);
	env = get_env(envp);
	args = get_args(argv);
	if (!args)
		return (-1);
	filename = args[0];
	if (argd)
		ft_putstr_fd(argd, 0);
	pid = fork();
	if (pid == 0)
	{
		filename = flnm(env, filename);
		execve(filename, args, envp);
	}
	else
		wait(NULL);
	free(argd);
	return (0);
}
