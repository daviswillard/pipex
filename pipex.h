#ifndef PIPEX_H
# define PIPEX_H

# include "./libft/libft.h"
# include <sys/wait.h>
# include <fcntl.h>

int		pipex(char **argv);

char	*rd_arg1(char **argv);

#endif
