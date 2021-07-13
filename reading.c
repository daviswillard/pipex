#include "pipex.h"

char	*rd_arg1(char **argv)
{
	int		fd;
	size_t	redd;
	char	buffer[101];
	char	*line;
	char	*tmp;

	if (access(argv[1], 4))
		return (ft_strdup("permission denied\n"));
	fd = open(argv[1], O_RDWR);
	if (fd < 0)
		return (ft_strdup("permission denied\n"));
	line = ft_calloc(1, 1);
	redd = read(fd, buffer, 100);
	while (redd > 0)
	{
		buffer[redd] = '\0';
		tmp = line;
		line = ft_strjoin(line, buffer);
		free(tmp);
		redd = read(fd, buffer, 100);
	}
	if (redd < 0)
		return ("read error\n");
	close(fd);
	return (line);
}
