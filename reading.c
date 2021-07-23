#include "pipex.h"

int	fd_arg1(char **argv)
{
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putendl_fd("Permission denied. Check filenames: are pathnames "
			"absolute?", 1);
		exit (-1);
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
	return (0);
}
