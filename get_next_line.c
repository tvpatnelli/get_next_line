/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpatnell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 13:24:46 by vpatnell          #+#    #+#             */
/*   Updated: 2019/01/07 13:13:02 by vpatnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"


int		get_next_line(const int fd, char **line)
{
	static char tmp[BUFF_SIZE];

	while (read(fd, tmp , BUFF_SIZE) > 0)
		if (ft_strchr(tmp, '\n') ? 1 : -1)
				ft_strjoin(tmp , *line);

	return (0);
}

int		main(int arc , char **arv)
{
	int  fd;
	char *line;
if  (arc == 1)
	fd =0;
	else if (arc == 2)
		fd = open(arv[1], O_RDONLY);
	else 
		return (-1);
	while (get_next_line(fd, &line) == 1)
	{
		ft_putendl(line);
		free(line);
	}
	if  (arc ==  2)
		close (fd);
return (0);
}
