#include "libft.h"

int ft_isalnum(int ch)
{
    if  ((ft_isalpha(ch) || ft_isdigit(ch)))
        return(1);
    else 
        return(0);
}
