/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 18:42:44 by dwillard          #+#    #+#             */
/*   Updated: 2021/10/13 18:42:45 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	char	*filename;

	filename = NULL;
	if (argc < 5 && ft_strncmp(argv[1], "here_doc", 8))
		ft_putstr_fd("Wrong usage, try ./pipex file1 cmd1 cmd2 file2\n", 1);
	else if (argc < 6 && !ft_strncmp(argv[1], "here_doc", 8))
		ft_putendl_fd("try ./pipex here_doc LIMITER cmd cmd1 file", 1);
	else
		pipex(argv, envp, filename, argc);
	return (0);
}
