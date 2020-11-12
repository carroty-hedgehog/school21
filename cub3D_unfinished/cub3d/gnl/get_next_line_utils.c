/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tredtusk <tredtusk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 17:54:17 by tredtusk          #+#    #+#             */
/*   Updated: 2020/09/30 18:18:49 by tredtusk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char		*ft_strdup_free(char *str)
{
	char	*dst;
	char	*temp;

	temp = (char *)malloc(sizeof(*dst) * (ft_strlen(str) + 1));
	if (!temp)
		return (NULL);
	dst = temp;
	while (*str)
	{
		*temp = *str;
		temp++;
		str++;
	}
	*temp = '\0';
	return (dst);
}

char		*ft_strjoin_free(char *s1, char *s2)
{
	char	*str;
	char	*res;
	size_t	len1;
	size_t	len2;

	if (!s1 && !s2)
		return (NULL);
	if (!(s1) || !(s2))
		return (!(s1) ? ft_strdup_free(s2) : ft_strdup_free(s1));
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(str = (char *)malloc(sizeof(char) * (len1 + len2 + 1))))
		return (0);
	res = str;
	while (*s1)
		*str++ = *s1++;
	free(s1 - len1);
	while (*s2)
		*str++ = *s2++;
	*str = '\0';
	return (res);
}

char		*ft_strchr_n(char *s)
{
	while (*s)
	{
		if (*s == '\n')
			return (s);
		s++;
	}
	return (0);
}
