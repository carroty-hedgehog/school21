/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tredtusk <tredtusk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 17:54:16 by tredtusk          #+#    #+#             */
/*   Updated: 2020/09/30 18:21:13 by tredtusk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# define FD 15000
# define BUFFER_SIZE 1

int		get_next_line(int fd, char **line);
size_t	ft_strlen(const char *s);
char	*ft_strdup_free(char *str);
char	*ft_strjoin_free(char *s1, char *s2);
char	*ft_strchr_n(char *s);

#endif
