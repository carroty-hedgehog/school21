#include "libft.h"

char	*ft_strdup(const char *src)
{
	int n;
	char *s;

	n = 0;
	while (src[n])
	n++;
	if (!(s = (char *)malloc(sizeof(*src)* (n + 1))))
	return (NULL);
	while (n >= 0)
	{
		s[n] = src[n];
		n--;
	}
	return (s);
}