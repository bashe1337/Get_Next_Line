/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bashe <bashe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 20:31:27 by bashe             #+#    #+#             */
/*   Updated: 2019/09/27 20:52:05 by bashe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef FT_GET_NEXT_LINE_H
# define FT_GET_NEXT_LINE_H
# include <unistd.h>
# include "libft.h"
# include <stdlib.h>

int		get_next_line(const int fd, char **line);

#endif
