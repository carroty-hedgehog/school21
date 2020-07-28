#include "libft.h"

int		ft_strncmp(const char *str1,const char *str2, size_t n)
{
	unsigned char *s1;
	unsigned char *s2;
	size_t i;

	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;

	i = 0;
	while (i < n && (s1[i] != '\0' && s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (i < n && ((s1[i] != '\0' && s2[i] == '\0')
				|| (s1[i] == '\0' && s2[i] != '\0')))
		return (s1[i] - s2[i]);
	return (0);
}
