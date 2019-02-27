#include "get_next_line.h"
#include "libft.h"
#include <stdio.h>

int		main(int arc, char **arv)
{
	int		fd;
	int		fd1;
	char	*line;
	int count = 0;
	int ret;

	fd = open(arv[1], O_RDONLY);
	fd1 =  open(arv[2], O_RDONLY);

	(get_next_line(fd, &line));
	ft_putendl(line);
	free(line);

	(get_next_line(fd, &line));
	ft_putendl(line);
	free(line);

	(get_next_line(fd1, &line));
	ft_putendl(line);
	free(line);

	(get_next_line(fd, &line));
	ft_putendl(line);
	free(line);

	(get_next_line(fd1, &line));
	ft_putendl(line);
	free(line);

	close(fd);
	close(fd1);
	return (0);
}
