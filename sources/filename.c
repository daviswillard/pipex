
#include "../pipex.h"

void	error(char *str)
{
	if (str)
		ft_putendl_fd(str, 2);
	if (errno && !str)
		ft_putendl_fd(strerror(errno), 2);
	exit(errno);
}

static void	freedom(char ***ret)
{
	int	counter;

	counter = 0;
	while ((*ret)[counter])
	{
		free((*ret)[counter]);
		(*ret)[counter++] = NULL;
	}
	free(*ret);
	*ret = NULL;
}

static char	*flnm(char **env, char *filename)
{
	int		check;
	int		index;
	char	*temp;

	check = 0;
	index = 0;
	if (!access(filename, F_OK))
		return (ft_strdup(filename));
	filename = ft_strjoin("/", filename);
	temp = ft_strjoin(env[index], filename);
	while (!check && temp)
	{
		if (!filename)
			error(NULL);
		printf("%s\n", temp);
		if (!access(temp, F_OK))
			check = 1;
		else
		{
			free(temp);
			temp = ft_strjoin(env[index++], filename);
		}
	}
	free(filename);
	errno = 0;
	return (temp);
}

void	argnfln(char *argv, char **env, char ***args, char **filename)
{
	if (*args)
		freedom(args);
	if (argv)
		*args = ft_split(argv, ' ');
	if (errno)
		error(NULL);
	if (*filename)
		free(*filename);
	if (argv)
	{
		*filename = flnm(env, *args[0]);
		if (!*filename)
			error(ft_strjoin("command not found: ", *args[0]));
	}
	else
		freedom(&env);
}