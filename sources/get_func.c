/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 19:31:51 by dwillard          #+#    #+#             */
/*   Updated: 2021/10/05 19:31:56 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	**get_env(char **envp)
{
	int		ind_glob;
	char	*path;
	char	**split;

	ind_glob = 0;
	path = ft_strnstr(envp[ind_glob++], "PATH", 4);
	while (!path && envp[ind_glob])
		path = ft_strnstr(envp[ind_glob++], "PATH", 4);
	if (!path)
		error("no $PATH was found in your env");
	path = ft_strchr(path, '/');
	split = ft_split(path, ':');
	if (!split)
		error(NULL);
	return (split);
}
