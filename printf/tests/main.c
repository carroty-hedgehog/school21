#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int main()
{
    printf("___________Test 1___________\n");
    printf("printf:    school\n");
    ft_printf("ft_printf: school\n");

    int a;
    printf("___________Test 2___________\n");
    printf("printf:    %c, %s, %d, %i, %u, %p, %x, %X, %%\n", 'a', "yes", 225, -132, 235, &a, 255, 255);
    ft_printf("ft_printf: %c, %s, %d, %i, %u, %p, %x, %X, %%\n", 'a', "yes", 225, -132, 235, &a, 255, 255);

    //Тесты для символов
    printf("___________Test 3___________\n");
    printf("printf:    %-%\n", 'A' , 5);
    ft_printf("ft_printf: %-%\n", 'A', 5);

    printf("___________Test 3/2___________\n");
    printf("printf:    %%d\n", 'A' , 5);
    ft_printf("ft_printf: %%d\n", 'A', 5);

    printf("___________Test 3/3___________\n");
    printf("printf:    %  %\n", 'A');
    ft_printf("ft_printf: %  %\n", 'A');

    printf("___________Test 4___________\n");
    printf("printf:    %c\n", 65);
    ft_printf("ft_printf: %c\n", 65);

    printf("___________Test 5___________\n");
    printf("printf:    %c\n", ' ');
    ft_printf("ft_printf: %c\n", ' ');

    //Тесты для строк
    //Дописать проверки на строки
    printf("___________Test 6___________\n");
    printf("printf:    %s\n", "asdf");
    ft_printf("ft_printf: %s\n", "asdf");

    //Тесты для int
    printf("___________Test 7___________\n");
    printf("printf:    %d\n", 15);
    ft_printf("ft_printf: %d\n", 15);

    printf("___________Test 8___________\n");
    printf("printf:    %d\n", -225);
    ft_printf("ft_printf: %d\n", -225);

    printf("___________Test 9___________\n");
    printf("printf:    %d\n", +225);
    ft_printf("ft_printf: %d\n", +225);

    printf("___________Test 10___________\n");
    printf("printf:    %d\n", INT_MAX);
    ft_printf("ft_printf: %d\n", INT_MAX);

    printf("___________Test 11___________\n");
    printf("printf:    %d\n", INT_MIN);
    ft_printf("ft_printf: %d\n", INT_MIN);

    printf("___________Test 12___________\n");
    printf("printf:    %d\n", 0);
    ft_printf("ft_printf: %d\n", 0);

    //Проверка типа %i
    printf("___________Test 13___________\n");
    printf("printf:    %i\n", -835);
    ft_printf("ft_printf: %i\n", -835);

    //проверка unsigned int
    printf("___________Test 14___________\n");
    printf("printf:    %u\n", 325);
    ft_printf("ft_printf: %u\n", 325);

    printf("___________Test 15___________\n");
    printf("printf:    %u\n", -325);
    ft_printf("ft_printf: %u\n", -325);

    printf("___________Test 16___________\n");
    printf("printf:    %u\n", UINT_MAX);
    ft_printf("ft_printf: %u\n", UINT_MAX);

    //Проверка вывода адресов
    int b;
    char c;
    char *str;

    printf("___________Test 17___________\n");
    printf("printf:    %p\n", &b);
    ft_printf("ft_printf: %p\n", &b);

    printf("___________Test 18___________\n");
    printf("printf:    %p\n", &c);
    ft_printf("ft_printf: %p\n", &c);

    printf("___________Test 19___________\n");
    printf("printf:    %p\n", str);
    ft_printf("ft_printf: %p\n", str);

    str = NULL;
    printf("___________Test 20___________\n");
    printf("printf:    %p\n", str);
    ft_printf("ft_printf: %p\n", str);


    printf("___________Test 21___________\n");
    printf("printf:    %X\n", 1235);
    ft_printf("ft_printf: %X\n", 1235);

    printf("___________Test 21___________\n");
    printf("printf:    %X\n", -1235);
    ft_printf("ft_printf: %X\n", -1235);

    //from slaka
    // printf("___________Test 23___________\n");
    // printf(“%-20% %%\n”,5);
    // ft_printf("%-20% %%\n,5”);

    // printf("___________Test 24___________\n");
    // printf("%9.1s\n", NULL);
    // ft_printf("%9.1s\n", NULL);


    printf("___________Test 25___________\n");
    printf("%%\n");
    ft_printf("%%\n");

    printf("___________Test 26___________\n");
    printf("%*.*i\n", 19, 14, -42);
    ft_printf("%*.*i\n", 19, 14, -42);

    printf("___________Test 27___________\n");
    printf("%*.*d\n", 4, 3, -12);
    ft_printf("%*.*d\n", 4, 3, -12);

    // printf("___________Test 28__________\n");
    // printf("%0*.*i\n", 2, 1, 8);
    // ft_printf("%0*.*i\n", 2, 1, 8);


    // Проверка на утечку памяти:
    // valgrind -v --tool=memcheck --leak-check=yes ./test
    return (0);
}



