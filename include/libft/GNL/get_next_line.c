/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarodri <anarodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 13:31:04 by cemenjiv          #+#    #+#             */
/*   Updated: 2023/03/14 15:31:39 by anarodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*show_line(char **s, char **line, int fd)
{
	int		len;
	char	*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	len = 0;
	while ((*s)[len] != '\n' && (*s)[len] != '\0')
		len++;
	if ((*s)[len] == '\n' && (*s)[len + 1] != '\0')
	{
		*line = ft_substr(*s, 0, len + 1);
		tmp = ft_strdup(&((*s)[len + 1]));
		free(*s);
		*s = tmp;
	}
	else
	{
		*line = ft_strdup(*s);
		free(*s);
		*s = NULL;
	}
	return (*line);
}

static char	*join_line(char **s, char **buf, char **tmp)
{
	if (*s == NULL)
		*s = ft_strdup(*buf);
	else
	{
		*tmp = ft_strjoin(*s, *buf);
		free(*s);
		*s = *tmp;
	}
	free (*buf);
	return (*s);
}

char	*get_next_line(int fd)
{
	static char	*str[FD_SIZE];
	char		*buf;
	char		*tmp;
	char		*line;
	int			ret;

	ret = 1;
	while (ret > 0 && fd >= 0)
	{
		buf = malloc(sizeof(*buf) * (BUFFER_SIZE + 1));
		ret = read (fd, buf, BUFFER_SIZE);
		if ((ret == 0 && str[fd] == NULL) || ret < 0)
		{
			free(buf);
			return (NULL);
		}
		buf[ret] = '\0';
		join_line(&str[fd], &buf, &tmp);
		if (ft_strchr(str[fd], '\n'))
			break ;
	}
	return (show_line(&str[fd], &line, fd));
}
