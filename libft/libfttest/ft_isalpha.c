#include "libft.h"

int ft_isalpha(int ch)
{
    if ((ft_islower(ch) || ft_isupper(ch)))
        return (1);
    else 
        return (0);
}
