#include "libft.h"

void    *ft_memchr(const void *str, int c, size_t n)

{
    unsigned char *s;
    unsigned char m;


    s = (unsigned char *)str;
    m = (unsigned char)c;
    while (n--)
    {
        if(*s == m)
            return (s);
        s++;
    }
        return (NULL);
}