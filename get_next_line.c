
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpatnell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 13:52:49 by vpatnell          #+#    #+#             */
/*   Updated: 2019/01/15 15:35:02 by vpatnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <stdio.h>



int		get_next_line(const int fd, char **line)
{
	char buff[BUFF_SIZE + 1];
	char *tmp;
	char *str;
	int ret;
	static char	 *rest;

	*line = ft_strnew(0);
	tmp = ft_strchr(buff , '\n');
	if (fd)
	{
		while ((ret = read(fd, buff , BUFF_SIZE)) > 0)
		{
			printf("\nbuff -> %s\n", buff);
			if(tmp)
			{
				*tmp ='\0';
				*line = ft_strjoin(*line, buff);
				*buff = *tmp + 1;
				printf("line -> %s", *line);
				printf("buff??? -> %s\n", buff);
				return (0);
			}
			else
				*line = ft_strjoin(*line, buff);
				printf("%s", *line);
		}
		return (1);
	}
	return (0);
}

int		main(int arc, char **arv)
{
	int		fd;
	char	*line;

	fd = open(arv[1], O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		ft_putstr(line);
			free(line);
	}
	close(fd);
	return (0);
}
