#include "../pipex.h"

int	main(int argc, char **argv, char **envp)
{
	char	*filename;

	filename = NULL;
	if (argc != 5)
		ft_putstr_fd("Wrong usage, try ./pipex file1 cmd1 cmd2 file2\n", 1);
	else
		pipex(argv, envp, filename);
	return (0);
}
