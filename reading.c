#include "pipex.h"

int	fd_arg(char **argv, int *fd)
{
	int		file1;
	int		file2;

	file1 = open(argv[1], O_RDONLY);
	file2 = open(argv[4], O_RDWR | O_TRUNC | O_CREAT);
	if (file1 < 0 || file2 < 0)
	{
		ft_putendl_fd("Permission denied. Check filenames: are pathnames "
			"absolute?", 1);
		exit (-1);
	}
	dup2(file1, STDIN_FILENO);
	close(file1);
	return (file2);
}
