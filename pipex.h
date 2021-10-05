#ifndef PIPEX_H
# define PIPEX_H
# define INPUT_END 1
# define OUTPUT_END 0

# include "./libft/libft.h"
# include <sys/wait.h>
# include <fcntl.h>

int		pipex(char **argv, char **envp, char *filename);

int		fd_arg(char **argv);

int		fd_arg2(char **argv);

char	**get_env(char **envp);

#endif