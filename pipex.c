#include "pipex.h"

int	pipex(char **argv)
{
	char	*argd;

	argd = rd_arg1(argv);
	if (argd)
		ft_putstr_fd(argd, 0);
	free(argd);
	return (0);
}
