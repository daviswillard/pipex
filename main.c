#include "pipex.h"

int	main(int argc, char **argv)
{
	if (argc != 5)
		ft_putstr_fd("Wrong usage, format is ./pipex file1 cmd1 cmd2 file2", 1);
	else
		pipex(argv);
	return (0);
}
