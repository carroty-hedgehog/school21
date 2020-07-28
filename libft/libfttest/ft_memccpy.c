#include "libft.h"
    
void *ft_memccpy (void *destination, const void *source, int c, size_t n)
{

    unsigned char *d;
    unsigned char *s;

    s = (unsigned char *)source;
    d = (unsigned char *)destination;
    if (!source && !destination)
        return (destination);
    while (n--)
    {
         *d = *s;
        if (*s == c)
          return (d + 1);
        d++;
        s++;
    }
    return (NULL);
}