/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bashe <bashe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 20:50:08 by bashe             #+#    #+#             */
/*   Updated: 2019/10/15 20:42:48 by bashe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include "stdio.h"

int		get_output(int ret)
{
	if (ret > 0)
		return (1);
	else if (ret < 0)
		return (-1);
	else
		return (0);
}
int		get_line(const int fd, char **line, char *remain)
{
	int			ret;
	char		buff[BUFF_SIZE + 1];
	char		*p;
	char		*tmp;

	p = NULL;
	*line = ft_strnew(1);
	if (remain)
		*line = ft_strdup(remain);
	while (!p && ((ret = read(fd, buff, BUFF_SIZE)) != 0))
	{
		buff[ret] = '\0';
		if ((p = ft_strchr(buff, '\n')))
		{
			*p = '\0';
			p++;
			remain = ft_strcpy(remain, p);
		}
		*line = ft_strjoin(*line, buff);
	}
	tmp = *line;
	ft_strdel(&tmp);
	return (get_output(ret));
}

t_gnl	*list_new_elem(int fd)
{
	t_gnl	*new_elem;

	new_elem = (t_gnl *)malloc(sizeof(t_gnl));
	new_elem->fd = fd;
	new_elem->remain = ft_strnew(BUFF_SIZE);
	new_elem->next = NULL;
	return (new_elem);
}

int		get_next_line(const int fd, char **line)
{
	static t_gnl	*head;
	t_gnl			*tmp;

	if (!line || fd < 0)
		return (-1);
	if (head == NULL)
		head = list_new_elem(fd);
	tmp = head;
	while (tmp != NULL)
	{
		if (tmp->fd == fd)
			break ;
		tmp = tmp->next;
	}
	if (tmp == NULL)
		tmp = list_new_elem(fd);
	return (get_line(tmp->fd, line, tmp->remain));
}

int main(void)
{
	char *line;
	int fd1;
	int fd2;

	fd1 = open("text.txt", O_RDONLY);
	fd2 = open("bruh.txt", O_RDONLY);
	get_next_line(fd1, &line);
	printf("%s\n\n", line);
	printf("%d\n", get_next_line(fd1, &line));
	get_next_line(fd2, &line);
	printf("%s\n\n", line);
	printf("%d\n", get_next_line(fd2, &line));
	get_next_line(fd1, &line);
	printf("%s\n\n", line);
	printf("%d\n", get_next_line(fd1, &line));
	// get_next_line(fd, &line);
	// printf("%s\n\n", line);
	// printf("%d\n", get_next_line(fd, &line));
	// get_next_line(fd, &line);
	// printf("%s\n\n", line);
	// printf("%d\n", get_next_line(fd, &line));
	// get_next_line(fd, &line);
	// printf("%s\n\n", line);
	// printf("%d\n", get_next_line(fd, &line));
	return (0);
}
