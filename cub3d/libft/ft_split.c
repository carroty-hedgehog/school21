/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tredtusk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 13:10:00 by tredtusk          #+#    #+#             */
/*   Updated: 2020/05/24 15:13:49 by tredtusk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_count_words(char const *s, char c)
{
	size_t			words;

	words = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			words++;
			while (*s && *s != c)
				s++;
		}
	}
	return (words);
}

void				ft_destroy_arr(void **ap)
{
	while (ap)
	{
		free(*ap);
		*ap = NULL;
		ap++;
	}
	free(ap);
}

static char			**ft_strsplit_ftn(const char *s, char c, size_t i, size_t d)
{
	int				start;
	int				end;
	char			**tab;

	tab = NULL;
	if (s && (tab = (char **)malloc(sizeof(*tab) * (ft_count_words(s, c) + 1))))
	{
		while (s[i] != '\0')
		{
			while (s[i] && s[i] == c)
				i++;
			start = i;
			while (s[i] && s[i] != c)
				i++;
			end = i;
			if (end > start)
				if (!(tab[d++] = ft_substr(s, start, (end - start))))
					ft_destroy_arr((void**)tab);
		}
	}
	else
		return (NULL);
	tab[d] = NULL;
	return (tab);
}

char				**ft_split(const char *s, char c)
{
	size_t			i;
	size_t			d;
	char			**tab;

	tab = NULL;
	i = 0;
	d = 0;
	tab = ft_strsplit_ftn(s, c, i, d);
	return (tab);
}
