#include "libft.h"

void    *ft_memset(void *s, int c, size_t n)
{
    unsigned char *str;
    unsigned char m;

    str = (unsigned char *)s;
    m = (unsigned char)c;
    while (n--)
        *str++ = m;
    return (s);
}

//* int main (void)
//{
  // Исходный массив
  // unsigned char s[15]="1234567890";
  //  Заполняем массив символом ‘1’
  // ft_memset (s, '2', 10);

   // Вывод массива src на консоль
  // printf ("s %s\n",s);

  // return 0;
//}