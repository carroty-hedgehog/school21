#include "libft.h"

int ft_toupper(int ch)      //в большие
{
    if (ft_islower(ch))
     return(ch - 32);
    else 
        return(ch);
}