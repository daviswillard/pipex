/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 19:01:04 by dwillard          #+#    #+#             */
/*   Updated: 2021/10/06 19:01:28 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# define INPUT_END 1
# define OUTPUT_END 0

# include "./libft/libft.h"
# include <sys/wait.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <stdio.h>

int		pipex(char **argv, char **envp, char *filename);

void	error(char *str);

void	argnfln(char *argv, char **env, char ***args, char **filename);

int		fd_arg(char **argv);

int		fd_arg2(char **argv);

char	**get_env(char **envp);

#endif
