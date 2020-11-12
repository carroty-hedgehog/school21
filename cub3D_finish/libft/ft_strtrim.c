/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tredtusk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 13:11:40 by tredtusk          #+#    #+#             */
/*   Updated: 2020/05/26 20:04:50 by tredtusk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	begin;
	size_t	end;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	begin = 0;
	end = ft_strlen(s1);
	while (s1[begin] && ft_strchr(set, s1[begin]))
		begin++;
	while (end > begin && ft_strchr(set, s1[end - 1]))
		end--;
	if (begin == end)
		return (ft_strdup(""));
	if (!(str = (char*)malloc(sizeof(*s1) * (end - begin + 1))))
		return (NULL);
	i = 0;
	while (begin < end)
		str[i++] = s1[begin++];
	str[i] = '\0';
	return (str);
}
