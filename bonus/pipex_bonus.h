/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 18:41:42 by dwillard          #+#    #+#             */
/*   Updated: 2021/10/13 18:43:49 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
# define INPUT_END 1
# define OUTPUT_END 0
# define BUFFER_SIZE 100

# include "../libft/libft.h"
# include <sys/wait.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <stdio.h>

int		pipex(char **argv, char **envp, char *filename, int argc);

void	error(char *str);

void	argnfln(char *argv, char **env, char ***args, char **filename);

int		fd_arg(char **argv);

int		fd_arg2(char **argv);

char	**get_env(char **envp);

int		get_next_line(char **line, int fd);

#endif
