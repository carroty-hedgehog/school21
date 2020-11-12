/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tredtusk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 13:11:20 by tredtusk          #+#    #+#             */
/*   Updated: 2020/05/28 00:21:03 by tredtusk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char		*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!(little))
		return ((char*)big);
	while (i < n && big[i] != '\0')
	{
		j = 0;
		while (i + j < n && little[j] != '\0' && big[i + j] == little[j])
			j++;
		if (little[j] == '\0')
			return ((char*)big + i);
		i++;
	}
	return (NULL);
}

int main ()
{
	char a[] = "asdfghj";
	char *b = NULL;

	printf("%s", ft_strnstr(a, b, 3));

	return(0);
}
