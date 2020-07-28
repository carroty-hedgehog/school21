#include "libft.h"

void    *ft_memcpy  (void *destination, const void *source, size_t n)
{
    unsigned char *d;
    unsigned char *s;

    s = (unsigned char *)source;
    d = (unsigned char *)destination;
    if (!source && !destination)
        return (destination);
    while (n--)
        *d++ = *s++;
    return (destination);
}
