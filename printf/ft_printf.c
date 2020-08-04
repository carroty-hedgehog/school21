

#include "ft_printf.h"

int				ft_printf(const char *input, ...)
{
	va_list		point;
	int			len;
	int			i;

	i = -1;
	len = 0;
	if (input == NULL)
		return (-1);
	va_start(point, input);
	len = ft_distribution(point, input, i, len);
	va_end(point);
	return (len);
}
