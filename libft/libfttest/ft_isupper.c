#include "libft.h"

int ft_isupper(int ch) 
{
    if (ch >= 'A' && ch <= 'Z')
        return (1);
    else
        return (0);
}