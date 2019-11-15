/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bashe <bashe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 14:29:45 by bpole             #+#    #+#             */
/*   Updated: 2019/11/15 18:31:24 by bashe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int		main(void)
{
	int		fd;
	int		fd2;
	int		fd3;
	int     fd4;
	char	*line;
    
   fd = open("1", O_RDONLY);
   get_next_line(fd, &line);
   printf("%s\n", line);

    fd = open("text.txt", O_RDONLY);
    get_next_line(fd, &line);
    printf("%s\n", line);
    free(line);

    fd2 = open("text2.txt", O_RDONLY);
    get_next_line(fd2, &line);
    printf("%s\n", line);
    free(line);

    get_next_line(0, &line);
    printf("%s\n", line);
	free(line);

     fd3 = open("text3.txt", O_RDONLY);
     while (get_next_line(fd3, &line) > 0) {
         printf("%s\n", line);
         free(line);
     }

    fd4 = open("text4.txt", O_RDONLY);
    while (get_next_line(fd4, &line) > 0) {
        printf("%s\n", line);
        free(line);
    }

	return (0);
}

//1234512345
//qwert
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpole <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 12:05:26 by bpole             #+#    #+#             */
/*   Updated: 2019/09/27 15:14:39 by bpole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//yuiop
//-1
//-1
