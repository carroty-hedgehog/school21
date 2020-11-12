/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tredtusk <tredtusk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 18:43:22 by tredtusk          #+#    #+#             */
/*   Updated: 2020/09/30 18:19:42 by tredtusk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int			make_new_line(char **fd_arr, char **line, char *p_new_line)
{
	char			*temp;

	*p_new_line++ = '\0';
	*line = ft_strdup_free(*fd_arr);
	if (*p_new_line == '\0')
	{
		free(*fd_arr);
		*fd_arr = NULL;
		return (1);
	}
	temp = ft_strdup_free(p_new_line);
	free(*fd_arr);
	*fd_arr = temp;
	return (1);
}

static int			check_lost(char **fd_arr, char **line, int bwr)
{
	char			*p_new_line;

	if (bwr < 0)
		return (-1);
	if (*fd_arr && (p_new_line = ft_strchr_n(*fd_arr)))
		return (make_new_line(fd_arr, line, p_new_line));
	if (*fd_arr)
	{
		*line = *fd_arr;
		*fd_arr = NULL;
		return (0);
	}
	*line = ft_strdup_free("");
	return (0);
}

int					get_next_line(int fd, char **line)
{
	static	char	*fd_arr[FD];
	char			buff[BUFFER_SIZE + 1];
	int				bwr;
	char			*p_new_line;

	if (!line || (fd < 0) || (read(fd, buff, 0) != 0) || BUFFER_SIZE <= 0)
		return (-1);
	while ((bwr = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[bwr] = '\0';
		fd_arr[fd] = ft_strjoin_free(fd_arr[fd], buff);
		if ((p_new_line = ft_strchr_n(fd_arr[fd])))
			return (make_new_line(&fd_arr[fd], line, p_new_line));
	}
	return (check_lost(&fd_arr[fd], line, bwr));
}
