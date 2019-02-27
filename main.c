#include "get_next_line.h"
#include "libft.h"
#include <stdio.h>

int		main(int arc, char **arv)
{
	int		fd;
	char	*line;
	int count = 0;

	fd = open(arv[1], O_RDONLY);
	while (get_next_line(fd, &line))
	{
		count++;
		ft_putendl(line);
		free(line);
	}
	close(fd);
	return (0);
}
