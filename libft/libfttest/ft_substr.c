#include "libft.h"

char
	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	
	if (!(str = (char*)malloc(sizeof(*s) * (len + 1))))
		return (NULL);
	i = 0;		//счетчик для символов
	j = 0;		//счетчик для количесва печатных элементов
	while (s[i])
	{
		if (i >= start && j < len)	// почему не i <= len ? тип чтобы \0 не попало?
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = '\0';			
	return (str);
}