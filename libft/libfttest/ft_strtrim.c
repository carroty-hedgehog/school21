#include "libft.h"

static int	ft_cravnenie(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)		//проводим проверку по set пока не встретим совпадение или пока строчка не закончится
			return (1);
		i++;
	}
	return (0); 					
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	begin;
	size_t	end;

	begin = 0;
	end = ft_strlen(s1);
	while (s1[begin] && ft_cravnenie(s1[begin], set)) //сравниваем с начала	*SET???
		begin++;
	
	while (end > begin && ft_cravnenie(s1[end - 1], set))	//сравниваем с конца
		end--;
	str = (char*)malloc(sizeof(*s1) * (end - begin + 1));	//выделяем память под оставшееся 
	if (!str)
		return (NULL);
	i = 0;
	while (begin < end)
		str[i++] = s1[begin++];
	str[i] = '\0';
	return (str);
}