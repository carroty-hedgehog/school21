#include "libft.h"

char *ft_strnstr(const char *big, const char *little, size_t n)
{
        size_t i;
        size_t j;

        i = 0;
        if (!(*little))
                return((char*)big);
        while (i < n && big[i] != '\0')
        {
                j = 0;
                while (i + j < n && little[j] != '\0' && big[i + j] == little[j])
                        j++;
                if (little[j] == '\0')
                        return((char*)big + i);
                i++;
        }
        return(NULL);
}