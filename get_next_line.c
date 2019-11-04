/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bashe <bashe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 20:50:08 by bashe             #+#    #+#             */
/*   Updated: 2019/11/04 18:39:29 by bashe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int		get_output(int ret, char **line, char *remain)
{
	if (ret > 0 || ft_strlen(remain) || ft_strlen(*line))
		return (1);
	else
		return (0);
}

char	*get_remain(char *remain, char **p)
{
	char	*str;
	char	*tmp;

	str = ft_strnew(1);
	tmp = str;
	if ((*p = ft_strchr(remain, '\n')))
	{
		**p = '\0';
		str = ft_strdup(remain);
		(*p)++;
		ft_strcpy(remain, *p);
	}
	else if (remain)
	{
		str = ft_strdup(remain);
		ft_strclr(remain);
	}
	ft_strdel(&tmp);
	return (str);
}

int		get_line(const int fd, char **line, char *remain)
{
	int			ret;
	char		buff[BUFF_SIZE + 1];
	char		*p;
	char		*tmp;

	p = NULL;
	ret = 1;
	*line = get_remain(remain, &p);
	while ((!p && ((ret = read(fd, buff, BUFF_SIZE)) != 0)))
	{
		buff[ret] = '\0';
		if ((p = ft_strchr(buff, '\n')))
		{
			ft_strcpy(remain, ++p);
			ft_strclr(--p);
		}
		tmp = *line;
		if (!(*line = ft_strjoin(*line, buff)) || ret < 0)
			return (-1);
		ft_strdel(&tmp);
	}
	return (get_output(ret, line, remain));
}

t_gnl	*get_new_elem(int fd)
{
	t_gnl	*new_elem;

	new_elem = (t_gnl *)malloc(sizeof(t_gnl));
	if (new_elem == NULL)
		return (NULL);
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
		head = get_new_elem(fd);
	tmp = head;
	while (tmp != NULL)
	{
		if (tmp->fd == fd)
			break ;
		tmp = tmp->next;
	}
	if (tmp == NULL)
	{
		tmp = get_new_elem(fd);
		tmp->next = head;
		head = tmp;
	}
	return (get_line(tmp->fd, line, tmp->remain));
}

int main (void)
{
	int fd;
	char *line;

	fd = open("gnl1_2.txt", O_RDONLY);
	line = NULL;
	while (get_next_line(fd, &line))
		printf("%s\n", line);
}