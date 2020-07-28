#include "libft.h"

char    *ft_strchr(const char *s, int c)
{
  char m;
  
  m = (char)c;
    while (*s != '\0')
        if(*s++ == m)
            return ((char *)s - 1);
    if (!c && *s == '\0')
        return ((char *)s);
    return (NULL);
} 
