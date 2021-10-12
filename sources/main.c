/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 19:31:41 by dwillard          #+#    #+#             */
/*   Updated: 2021/10/05 19:32:04 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	main(int argc, char **argv, char **envp)
{
	char	*filename;

	filename = NULL;
	if (argc != 5)
		ft_putstr_fd("Wrong usage, try ./pipex file1 cmd1 cmd2 file2\n", 1);
	else
		pipex(argv, envp, filename, argc);
	return (0);
}
