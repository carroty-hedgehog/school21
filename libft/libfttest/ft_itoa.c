#include "libft.h"

static size_t		ft_itoa_len(int n)
{
	size_t	r;

	r = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		r++;
	while (n)
	{
		n /= 10;
		r++;
	}
	return (r);
}

char				*ft_itoa(int n)
{
	size_t	l;
	size_t	e;
	char	*r;

	l = ft_itoa_len(n);
	if (!(r = (char *)malloc(l + 1)))
		return (NULL);
	r[l] = '\0';
	if (n < 0)
	{
		r[0] = '-';
		e = 1;
	}
	else
		e = 0;
	while (l-- > e)
	{
		r[l] = '0' + n % 10 * (n < 0 ? -1 : 1);
		n /= 10;
	}
	return (r);
}