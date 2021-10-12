/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 19:31:25 by dwillard          #+#    #+#             */
/*   Updated: 2021/10/05 19:32:01 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	fd_arg(char **argv)
{
	int		file1;

	file1 = open(argv[1], O_RDONLY);
	if (errno)
		error(NULL);
	dup2(file1, STDIN_FILENO);
	close(file1);
	return (0);
}

int	fd_arg2(char **argv, int argc)
{
	int	file2;

	file2 = open(argv[argc - 1], O_RDWR | O_TRUNC | O_CREAT, 0622);
	if (errno)
		error(NULL);
	dup2(file2, STDOUT_FILENO);
	close(file2);
	return (0);
}
