#include <stdio.h>
#include "ft_printf.h"

int main()
{
    size_t i;

    i = 0;
    printf("___________Test 1___________\n");
    printf("printf:    %.*d|\n", -10, 123456);
    ft_printf("ft_printf: %.*d|\n", -10, 123456);

    printf("________________________________Test 2________________________________\n");
    printf("printf:    %.*d|\n", -3, 123456);
    ft_printf("ft_printf: %.*d|\n", -3, 123456);

    printf("________________________________Test 3________________________________\n");
    printf("printf:    %.*s|\n", -3, "123456");
    ft_printf("ft_printf: %.*s|\n",-3, "123456");

    printf("________________________________Test 4________________________________\n");
    printf("printf:    %*.*s|\n", -10, 3, "123456");
    ft_printf("ft_printf: %*.*s|\n", -10, 3, "123456");

    printf("________________________________Test 5________________________________\n" );
    printf("printf:    %-10.*s|\n", -3, "123456");
    ft_printf("ft_printf: %-10.*s|\n", -3, "123456");

    printf("________________________________Test 6________________________________\n" );
    printf("printf:    %-.*s|\n", 3, "123456");
    ft_printf("ft_printf: %-.*s|\n", 3, "123456");

    printf("________________________________Test 7________________________________\n" );
    printf("printf:    %-10.*d|\n", 3, 5);
    ft_printf("ft_printf: %-10.*d|\n", 3, 5);

    // printf("________________________________Test 8________________________________\n" );
    // printf("printf:    %-0.*d|\n", 3, 5);
    // ft_printf("ft_printf: %-0.*d|\n", 3, 5);

    printf("________________________________Test 11________________________________\n" );
    printf("printf:    %-.*d|\n", 3, 5);
    ft_printf("ft_printf: %-.*d|\n", 3, 5);

    printf("________________________________Test 12________________________________\n" );
    printf("printf:    %-*.*d|\n", 7, 3, 5);
    ft_printf("ft_printf: %-*.*d|\n", 7, 3, 5);

    printf("________________________________Test 13________________________________\n" );
    printf("printf:    %-*.5d|\n", 7, 5);
    ft_printf("ft_printf: %-*.5d|\n", 7, 5);

    // printf("________________________________Test 14________________________________\n" );
    // printf("printf:    %0.3d|\n", 5);
    // ft_printf("ft_printf: %0.3d|\n", 5);

    // printf("________________________________Test 15________________________________\n" );
    // printf("printf:    %0.3s|\n", "asdfghj");
    // ft_printf("ft_printf: %0.3s|\n", "asdfghj");

    // printf("________________________________Test 16________________________________\n" );
    // printf("printf:    %0-3.d|\n", 123);
    // ft_printf("ft_printf: %0-3.d|\n", 123);

    // printf("________________________________Test 17_______________________________\n" );
    // printf("printf:    %010s|\n", "asdfghj");
    // ft_printf("ft_printf: %010s|\n", "asdfghj");

    // printf("________________________________Test 18________________________________\n" );
    // printf("printf:    %0*s|\n", 13, "asdfghj");
    // ft_printf("ft_printf: %0*s|\n", 13, "asdfghj");

    // printf("________________________________Test 19________________________________\n" );
    // printf("printf:    %--10s|\n", "asdfghj");
    // ft_printf("ft_printf: %--10s|\n", "asdfghj");

    // printf("________________________________Test 20________________________________\n" );
    // printf("printf:    %00d|\n", 25);
    // ft_printf("ft_printf: %00d|\n", 25);

    // printf("________________________________Test 21_______________________________\n" );
    // printf("printf:    %..d|\n", 25);
    // ft_printf("ft_printf: %..d|\n", 25);

    printf("________________________________Test 22________________________________\n" );
    printf("printf:    %d|\n", 123456);
    ft_printf("ft_printf: %d|\n", 123456);

    printf("________________________________Test  23________________________________\n" );
    printf("printf:    %6d|\n", 123456);
    ft_printf("ft_printf: %6d|\n", 123456);

    printf("________________________________Test 24________________________________\n" );
    printf("printf:    %16d|\n", 123456);
    ft_printf("ft_printf: %16d|\n", 123456);

    printf("________________________________Test 25________________________________\n" );
    printf("printf:    %3s|\n", "asdf");
    ft_printf("ft_printf: %3s|\n", "asdf");

    printf("________________________________Test 26________________________________\n" );
    printf("printf:    %4s|\n", "asdf");
    ft_printf("ft_printf: %4s|\n", "asdf");

    printf("________________________________Test 27________________________________\n" );
    printf("printf:    %10s|\n", "asdf");
    ft_printf("ft_printf: %10s|\n", "asdf");

    printf("________________________________Test 28________________________________\n" );
    printf("printf:    %10x|\n", 123456);
    ft_printf("ft_printf: %10x|\n", 123456);

    printf("________________________________Test 29________________________________\n" );
    printf("printf:    %10X|\n", 123456);
    ft_printf("ft_printf: %10X|\n", 123456);

    printf("________________________________Test 30________________________________\n" );
    printf("printf:    %010d|\n", 123456);
    ft_printf("ft_printf: %010d|\n", 123456);
    
    printf("________________________________Test 31________________________________\n" );
    printf("printf:    %03d|\n", 123456);
    ft_printf("ft_printf: %03d|\n", 123456);

    printf("________________________________Test 32________________________________\n" );
    printf("printf:    %06d|\n", 123456);
    ft_printf("ft_printf: %06d|\n", 123456);

    printf("________________________________Test 33________________________________\n" );
    printf("printf:    %06u|\n", -567);
    ft_printf("ft_printf: %06u|\n", -567);

    printf("________________________________Test 34________________________________\n" );
    printf("printf:    %06u|\n", 567);
    ft_printf("ft_printf: %06u|\n", 567);

    printf("________________________________Test 35________________________________\n" );
    printf("printf:    %.20s|\n", "asdfghjklmnopppp");
    ft_printf("ft_printf: %.20s|\n", "asdfghjklmnopppp");

    printf("________________________________Test 36________________________________\n" );
    printf("printf:    %.3s|\n", "123456");
    ft_printf("ft_printf: %.3s|\n", "123456");

    printf("________________________________Test 37________________________________\n" );
    printf("printf:    %.6s|\n", "123456");
    ft_printf("ft_printf: %.6s|\n", "123456");

    printf("________________________________Test 38________________________________\n" );
    printf("printf:    %.0s|\n", "123456");
    ft_printf("ft_printf: %.0s|\n", "123456");

    printf("________________________________Test 39________________________________\n" );
    printf("printf:    %.5d|\n", 23);
    ft_printf("ft_printf: %.5d|\n", 23);

    printf("________________________________Test 40________________________________\n" );
    printf("printf:    %.0X|\n", 23);
    ft_printf("ft_printf: %.0X|\n", 23);

    printf("________________________________Test 41________________________________\n" );
    printf("printf:    %*d|\n", 10, 123456);
    ft_printf("ft_printf: %*d|\n", 10, 123456);

    printf("________________________________Test 42________________________________\n" );
    printf("printf:    %*d|\n", 3, 123456);
    ft_printf("ft_printf: %*d|\n", 3, 123456);

    printf("________________________________Test 43________________________________\n" );
    printf("printf:    %*d|\n", 6, 123456);
    ft_printf("ft_printf: %*d|\n", 6, 123456);
    return (0);
}