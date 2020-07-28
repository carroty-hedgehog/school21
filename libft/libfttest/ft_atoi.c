#include "libft.h"

int		ft_atoi(const char *str)
{
	int s;
	int i;
	int r;
	int m;

	s = 0;
	while ((str[s] != '\0') &&
		(str[s] == ' ' || str[s] == '\t' ||
		str[s] == '\n' || str[s] == '\r' || str[s] == '\v' || str[s] == '\f'))
		s++;
	i = s;
	r = 0;
	m = 1;
	while (str[i] != '\0' &&
			((str[i] <= '9' && str[i] >= '0') ||
			(i == s && (str[i] == '+' || str[i] == '-'))))
	{
		if (str[i] == '-')
			m = -1;
		if (str[i] >= '0' && str[i] <= '9')
			r = (r * 10) + (str[i] - '0');
		i++;
	}
	return (r * m);
}
