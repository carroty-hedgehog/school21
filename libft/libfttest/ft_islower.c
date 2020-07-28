#include "libft.h"

int ft_islower(int ch)
{
    if (ch >= 'a' && ch <= 'z')
        return (1);
    else
        return (0);
}