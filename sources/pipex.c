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

static void	child(int fd[2], char *filename, char **args)
{
	close(fd[OUTPUT_END]);
	dup2(fd[INPUT_END], STDOUT_FILENO);
	close(fd[INPUT_END]);
	execve(filename, args, NULL);
}

int	pipex(char **argv, char **envp, char *filename)
{
	char	**env;
	char	**args;
	int		fd[2];
	int		pid;

	args = NULL;
	env = get_env(envp);
	pipe(fd);
	fd_arg(argv);
	argnfln(argv[2], env, &args, &filename);
	pid = fork();
	if (pid < 0)
		error(NULL);
	else if	(!pid)
		child(fd, filename, args);
	else
	{
		fd_arg2(argv);
		argnfln(argv[3], env, &args, &filename);
		last_fork(&args, fd, filename);
	}
	argnfln(NULL, env, &args, &filename);
	return (0);
}
