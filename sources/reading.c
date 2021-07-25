#include "../pipex.h"

int	fd_arg(char **argv)
{
	int		file1;

	file1 = open(argv[1], O_RDONLY);
	if (file1 < 0)
	{
		ft_putendl_fd("Permission denied. Check filenames: are pathnames "
			"absolute?", 2);
		exit (-1);
	}
	dup2(file1, STDIN_FILENO);
	close(file1);
	return (0);
}

int	fd_arg2(char **argv)
{
	int	file2;

	file2 = open(argv[4], O_RDWR | O_TRUNC | O_CREAT, 0622);
	if (file2 < 0)
	{
		ft_putendl_fd("Permission denied. Check filenames: are pathnames "
			"absolute?", 2);
		exit (-1);
	}
	dup2(file2, STDOUT_FILENO);
	close(file2);
	return (0);
}
