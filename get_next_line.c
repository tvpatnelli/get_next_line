
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpatnell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 13:52:49 by vpatnell          #+#    #+#             */
/*   Updated: 2019/01/18 17:20:37 by vpatnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <stdio.h>

static char *chr_n(const int fd,char  *buff)
{
	char *tmp;
	char *str;

	tmp = ft_strchr(buff, '\n');
	str = ft_strnew(BUFF_SIZE);

	if (tmp)
	{
		*tmp = '\0';
		str = ft_strjoin(str , buff);
		*buff = *tmp + 1;
	}
	else
		str = ft_strjoin(str , buff);
	return (str);
}


int		get_next_line(const int fd, char **line)
{
	static char buff[BUFF_SIZE + 1];
	int ret;

	/*ft_putstr("////////// value  ////////\n");
	ft_putstr(buff);
	ft_putstr("\n////////// ////////\n");*/
	*line = ft_strnew(0);
	if  (fd)
	{
		while ((ret = read(fd, buff , BUFF_SIZE)) > 0)
			if (ret)
			{
				*line = ft_strjoin(*line, chr_n(fd, buff));
				return (1);
			}
		else
			return (0);
	}
	return (0);
}


int		main(int arc, char **arv)
{
	int		fd;
	char	*line;
	int count = 0;

	fd = open(arv[1], O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		count++;
		ft_putendl(line);
			free(line);
	}
	close(fd);
	return (0);
}
