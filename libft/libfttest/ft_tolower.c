#include "libft.h"

int ft_tolower(int ch)        
{
    if (ft_isupper(ch))
        return(ch + 32);
    return(ch);
}