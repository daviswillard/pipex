/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 15:56:48 by dwillard          #+#    #+#             */
/*   Updated: 2021/07/25 17:18:35 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	main(void)
{
	int		fd[2];
//	int		fdd[2];
	int		fd1;
	int		fd2;

	pipe(fd);
	fd1 = open("envtest.c", O_RDONLY);
	dup2(fd1, STDIN_FILENO);
	close(fd1);
	char *a[3];
	a[0] = "";
	a[1] = "a";
	a[2] = NULL;
	char *b[3];
	b[0] = "";
	b[1] = "-l";
	b[2] = NULL;
	if (!fork())
	{
		dup2(fd[INPUT_END], STDOUT_FILENO);
		close(fd[INPUT_END]);
		close(fd[OUTPUT_END]);
		execve("/usr/bin/grep", a, NULL);
	}
	else
	{
		close(fd[INPUT_END]);
//		pipe(fdd);
		fd2 = open("test.txt", O_RDWR | O_TRUNC | O_CREAT);
		dup2(fd2, STDOUT_FILENO);
		close(fd2);
		if (!fork())
		{
			close(fd[INPUT_END]);
			dup2(fd[OUTPUT_END], STDIN_FILENO);
			close(fd[OUTPUT_END]);
			execve("/usr/bin/wc", b, NULL);
		}
		else
		{
			wait(NULL);
			wait(NULL);
		}
	}
	return (0);
}

#include "../pipex.h"

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

//copy of pipex function
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
	if (!fork())
	{
		dup2(fd[INPUT_END], STDOUT_FILENO);
		close(fd[INPUT_END]);
		close(fd[OUTPUT_END]);
		execve(filename, args, NULL);
	}
	else
	{
		close(fd[INPUT_END]);
		fd_arg2(argv);
		if (!fork())
		{
			args = ft_split(argv[3], ' ');
			if (!args)
				return (-1);
			filename = flnm(env, args[0]);
			close(fd[INPUT_END]);
			dup2(fd[OUTPUT_END], STDIN_FILENO);
			close(fd[OUTPUT_END]);
			execve(filename, args, NULL);
		}
		else
		{
			wait(NULL);
			wait(NULL);
			close(fd[INPUT_END]);
			close(fd[OUTPUT_END]);
		}
	}
	return (0);
}
