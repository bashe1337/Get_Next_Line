/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bashe <bashe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 20:50:08 by bashe             #+#    #+#             */
/*   Updated: 2019/10/13 19:56:20 by bashe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include "stdio.h"

int		get_next_line(const int fd, char **line)
{
	int			ret;
	char		buff[BUFF_SIZE + 1];
	char		*p;
	char		*tmp;
	char		*remain;

	if (!line || fd < 0)
		return (-1);
	*line = ft_strnew(1);
	while (!p && ((ret = read(fd, &buff, BUFF_SIZE)) > 0))
	{
		buff[ret] = '\0';
		if ((p = ft_strchr(buff, '\n')))
		{
			*p = '\0';
			p++;
			remain = ft_strdup(p);
		}
		tmp = *line;
		*line = ft_strjoin(*line, buff);
		free(tmp);
	}
	return (0);
}


int main(void)
{
	char *line;
	int fd;

	fd = open("text.txt", O_RDONLY);
	get_next_line(fd, &line);
	printf("%s\n", line);
	get_next_line(fd, &line);
	printf("%s\n", line);
	return (0);
}
