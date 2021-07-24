#include "pipex.h"

int	fd_arg(char **argv)
{
	int		file1;

	file1 = open(argv[1], O_RDONLY);
	if (file1 < 0)
	{
		ft_putendl_fd("Permission denied. Check filenames: are pathnames "
			"absolute?", 1);
		exit (-1);
	}
	dup2(file1, STDIN_FILENO);
	close(file1);
	return (0);
}

int	fd_arg2(char **argv, int *fd)
{
	int	file2;

	file2 = open(argv[4], O_RDWR | O_TRUNC | O_CREAT);
	if (file2 < 0)
	{
		ft_putendl_fd("Permission denied. Check filenames: are pathnames "
					  "absolute?", 1);
		exit (-1);
	}
	dup2(fd[OUTPUT_END], file2);
	close(fd[OUTPUT_END]);
	return (0);
}
