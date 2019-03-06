#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"
#include <stdlib.h>
int main(int argc, char **argv)
{

int	fd;
char	*line;

fd = open(argv[1], O_RDONLY);
while (get_next_line(fd, &line) > 0)
{
	printf("%s\n", line);
	free(line);
}
return (0);
}
