#include "pipex.h"

static char	*flnm(char **env, char *filename)
{
	int		check;
	int		index;
	char	*temp;

	check = 0;
	index = 0;
	filename = ft_strjoin("/", filename);
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
			temp = ft_strjoin(env[index++], filename);
		}
	}
	return (temp);
}

int	pipex(char **argv, char **envp)
{
	char	**env;
	char	**args;
	char	*filename;
	int		fd[2];

	env = get_env(envp);
	args = ft_split(argv[2], ' ');
	pipe(fd);
	fd_arg(argv);
	if (!args)
		return (-1);
	filename = flnm(env, args[0]);
	if (fork())
	{
		close(fd[OUTPUT_END]);
		dup2(fd[INPUT_END], STDOUT_FILENO);
		close(fd[INPUT_END]);
		execve(filename, args, NULL);
	}
	else
	{
		if (fork())
		{
			args = ft_split(argv[3], ' ');
			if (!args)
				return (-1);
			filename = flnm(env, args[0]);
			fd_arg2(argv, fd);
			execve(filename, args, NULL);
		}
		else
		{
			waitpid(0, NULL, 0);
			waitpid(0, NULL, 0);
			close(fd[INPUT_END]);
			close(fd[INPUT_END]);
		}
	}
	return (0);
}
