/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpatnell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 12:46:40 by vpatnell          #+#    #+#             */
/*   Updated: 2019/02/27 20:35:26 by vpatnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <stdio.h>


static char		*joinandfree(char *tmp, char *buff)
{
	char		*fraiche;

	if (!tmp || !buff)
		return (NULL);
	if (tmp && !buff)
		return (tmp);
	if (!tmp && buff)
		return (ft_strdup(buff));
	if (!(fraiche = ft_strnew(ft_strlen(tmp) + ft_strlen(buff))))
		return (NULL);
	fraiche = ft_strcpy(fraiche, tmp);
	fraiche = ft_strcat(fraiche, buff);
	free(tmp);
	return (fraiche);
}

static char		*before_n(char *tmp, char *n)
{
	char		*ret;

	ret = ft_strsub(tmp, 0, n - tmp);
	return (ret);
}

static char		*buffrest(char *tmp, char *n)
{
	char		*rest;

	rest = NULL;
	if (!tmp)
		return (NULL);
	if (ft_strlen(n + 1) == 0)
		return (NULL);
	if (n + 1)
		rest = ft_strdup(n + 1);
	return (rest);
}

int				gagne_ligne(char **n, char **line, char **tmp)
{
	*line = before_n(*tmp, *n);
	*tmp = buffrest(*tmp, *n);
	if (*tmp != NULL)
		*n = ft_strchr(*tmp, '\n');
	else
		*n = NULL;
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static char *tmp;
	static char *n;
	char		buff[BUFF_SIZE + 1];
	int			ret;

	*line = ft_strnew(0);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		if (tmp == NULL)
			tmp = ft_strnew(0);
		buff[ret] = '\0';
		tmp = joinandfree(tmp, buff);
		if ((n = ft_strchr(tmp, '\n')) != NULL)
			break ;
	}
	if (n)
		return (gagne_ligne(&n, line, &tmp));
	if ((ret == 0 && tmp != NULL) ? *line = joinandfree(*line, tmp) : 0)
	{
		free(tmp);
		tmp = NULL;
		return (1);
	}
	return (ret != 0 ? -1 : 0);
}

