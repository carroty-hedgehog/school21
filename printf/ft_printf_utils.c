

#include "ft_printf.h"

int			ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int			ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - ('z' - 'Z'));
	return (c);
}

static int	ft_len(long long nb)
{
	int		len;

	len = 0;
	if (nb < 0)
	{
		nb = nb * -1;
		len++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(long long n)
{
	char	*num;
	int		i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	i = ft_len(n);
	if (!(num = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	num[i] = '\0';
	i--;
	if (n < 0)
	{
		n = (-1) * n;
		num[0] = '-';
	}
	while (n > 0)
	{
		num[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	return (num);
}

char		*ft_strdup(const char *src)
{
	int		i;
	char	*dest;

	i = 0;
	while (src[i] != '\0')
		i++;
	dest = (char*)malloc(sizeof(*src) * (i + 1));
	if (dest == NULL)
		return (NULL);
	else
	{
		i = 0;
		while (src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
		return (dest);
	}
}
