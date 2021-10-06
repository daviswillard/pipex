/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 19:31:32 by dwillard          #+#    #+#             */
/*   Updated: 2021/10/06 19:00:51 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static void	last_fork(char ***args, int *fd, char *filename)
{
	close(fd[INPUT_END]);
	wait(NULL);
	if (!fork())
	{
		close(fd[INPUT_END]);
		dup2(fd[OUTPUT_END], STDIN_FILENO);
		close(fd[OUTPUT_END]);
		execve(filename, *args, NULL);
	}
	else
		wait(NULL);
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
	free(filename);
	return (temp);
}

static void	argnfln(char *argv, char **env, char ***args, char **filename)
{
	if (*args)
		freedom(args);
	if (argv)
		*args = ft_split(argv, ' ');
	if (!(*args) && argv)
		exit(-1);
	if (*filename)
		free(*filename);
	if (argv)
	{
		*filename = flnm(env, *args[0]);
		if (!*filename)
		{
			ft_putstr_fd("command not found: ", 2);
			ft_putendl_fd(*args[0], 2);
			exit(-1);
		}
	}
	else
		freedom(&env);
}

int	pipex(char **argv, char **envp, char *filename)
{
	char	**env;
	char	**args;
	int		fd[2];

	args = NULL;
	env = get_env(envp);
	pipe(fd);
	fd_arg(argv);
	argnfln(argv[2], env, &args, &filename);
	if (!fork())
	{
		close(fd[OUTPUT_END]);
		dup2(fd[INPUT_END], STDOUT_FILENO);
		close(fd[INPUT_END]);
		execve(filename, args, NULL);
	}
	else
	{
		fd_arg2(argv);
		argnfln(argv[3], env, &args, &filename);
		last_fork(&args, fd, filename);
	}
	argnfln(NULL, env, &args, &filename);
	return (0);
}
