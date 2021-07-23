#ifndef PIPEX_H
# define PIPEX_H

# include "./libft/libft.h"
# include <sys/wait.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>

int		pipex(char **argv, char **envp);

int		fd_arg1(char **argv);

char	**get_env(char **envp);

#endif
