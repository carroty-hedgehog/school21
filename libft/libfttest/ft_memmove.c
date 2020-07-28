#include "libft.h"

void *ft_memmove (void *destination, const void *source, size_t n)
{
    unsigned char *d;
    unsigned char *s;

    s = (unsigned char *)source;
    d = (unsigned char *)destination;
    if (!source && !destination)
        return (destination);
    if (source < destination )
        while (n--)
            d[n] = s[n];
    else 
        while (n--)
         {
             *d = *s;
             d++;
             s++;
        }
    return (destination);
}