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
	char	*argd;
	char	**env;
	pid_t	pid;
	char	**args;
	char	*filename;

	argd = rd_arg1(argv);
	env = get_env(envp);
	args = get_args(argv[2]);
	if (!args)
		return (-1);
	filename = flnm(env, args[0]);
	printf("%s\n%s\n", args[0], filename);
	pid = fork();
	if (pid == 0)
	{
		execve(filename, args, NULL);
//		execve("/bin/cat", args, NULL);
		ft_putstr_fd("Command not found", 1);
	}
	else
		waitpid(0, NULL, 0);
	free(argd);
	return (0);
}
