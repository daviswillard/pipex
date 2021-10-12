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
#include <stdio.h>

static void	last_fork(char ***args, char *filename, char **argv)
{
	int		pid;
	int		fd[2];

	if (pipe(fd) < 0)
		error(NULL);
	close(fd[INPUT_END]);
	fd_arg2(argv);
	pid = fork();
	if (pid < 0)
		error(NULL);
	else if (pid == 0)
	{
		close(fd[OUTPUT_END]);
		dup2(fd[INPUT_END], STDOUT_FILENO);
		close(fd[INPUT_END]);
		execve(filename, *args, NULL);
	}
	else
	{
		close(fd[OUTPUT_END]);
		dup2(fd[INPUT_END], STDIN_FILENO);
		wait(NULL);
	}
}

static void	child(char *filename, char **args, int fd[2])
{
	int	pid;

	if (pipe(fd) < 0)
		error(NULL);
	pid = fork();
	if (pid < 0)
		error(NULL);
	else if (!pid)
	{
		close(fd[OUTPUT_END]);
		dup2(fd[INPUT_END], STDOUT_FILENO);
		close(fd[INPUT_END]);
		if (execve(filename, args, NULL) < 0)
			error(NULL);
	}
	else
	{
		close(fd[INPUT_END]);
		dup2(fd[OUTPUT_END], STDIN_FILENO);
		wait(NULL);
	}
}

int	here_doc(char *limiter)
{
	pid_t	reader;
	int		fd[2];
	char	*line;

	if (pipe(fd) == -1)
		error(NULL);
	reader = fork();
	if (reader == 0)
	{
		close(fd[0]);
		while (get_next_line(&line, STDIN_FILENO))
		{
			if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
				exit(0);
			ft_putendl_fd(line, fd[1]);
		}
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		wait(NULL);
	}
	return (3);
}

int	pipex(char **argv, char **envp, char *filename, int argc)
{
	char	**env;
	char	**args;
	int		index;
	int		fd[2];

	args = NULL;
	index = 2;
	env = get_env(envp);
	if (!ft_strncmp(argv[1], "here_doc", 8))
		index = here_doc(argv[2]);
	else
		fd_arg(argv);
	while (index < argc - 2)
	{
		argnfln(argv[index++], env, &args, &filename);
		if (pipe(fd) < 0)
			error(NULL);
		child(filename, args, fd);
	}
	argnfln(argv[argc - 2], env, &args, &filename);
	last_fork(&args, filename, argv);
	argnfln(NULL, env, &args, &filename);
	return (0);
}
