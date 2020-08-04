#include <stdio.h>
#include "ft_printf.h"

int main()
{
    size_t i;

    i = 0;
    printf("________________________________Test %ld________________________________\n", i++);
    printf("printf:    %.*d|\n", -10, 123456);
    ft_printf("ft_printf: %.*d|\n", -10, 123456);

    printf("________________________________Test %ld________________________________\n", i++);
    printf("printf:    %.*d|\n", -3, 123456);
    ft_printf("ft_printf: %.*d|\n", -3, 123456);

    printf("________________________________Test %ld________________________________\n", i++);
    printf("printf:    %.*s|\n", -3, "123456");
    ft_printf("ft_printf: %.*s|\n",-3, "123456");

    printf("________________________________Test %ld________________________________\n", i++);
    printf("printf:    %*.*s|\n", -10, 3, "123456");
    ft_printf("ft_printf: %*.*s|\n", -10, 3, "123456");

    printf("________________________________Test %ld________________________________\n", i++);
    printf("printf:    %-10.*s|\n", -3, "123456");
    ft_printf("ft_printf: %-10.*s|\n", -3, "123456");

    printf("________________________________Test %ld________________________________\n", i++);
    printf("printf:    %-.*s|\n", 3, "123456");
    ft_printf("ft_printf: %-.*s|\n", 3, "123456");

    printf("________________________________Test %ld________________________________\n", i++);
    printf("printf:    %-10.*d|\n", 3, 5);
    ft_printf("ft_printf: %-10.*d|\n", 3, 5);

    // printf("________________________________Test %ld________________________________\n", i++);
    // printf("printf:    %-0.*d|\n", 3, 5);
    // ft_printf("ft_printf: %-0.*d|\n", 3, 5);

    printf("________________________________Test %ld________________________________\n", i++);
    printf("printf:    %-.*d|\n", 3, 5);
    ft_printf("ft_printf: %-.*d|\n", 3, 5);

    printf("________________________________Test %ld________________________________\n", i++);
    printf("printf:    %-*.*d|\n", 7, 3, 5);
    ft_printf("ft_printf: %-*.*d|\n", 7, 3, 5);

    printf("________________________________Test %ld________________________________\n", i++);
    printf("printf:    %-*.5d|\n", 7, 5);
    ft_printf("ft_printf: %-*.5d|\n", 7, 5);

    // printf("________________________________Test %ld________________________________\n", i++);
    // printf("printf:    %0.3d|\n", 5);
    // ft_printf("ft_printf: %0.3d|\n", 5);

    // printf("________________________________Test %ld________________________________\n", i++);
    // printf("printf:    %0.3s|\n", "asdfghj");
    // ft_printf("ft_printf: %0.3s|\n", "asdfghj");

    // printf("________________________________Test %ld________________________________\n", i++);
    // printf("printf:    %0-3d|\n", 123);
    // ft_printf("ft_printf: %0-3d|\n", 123);

    // printf("________________________________Test %ld________________________________\n", i++);
    // printf("printf:    %010s|\n", "asdfghj");
    // ft_printf("ft_printf: %010s|\n", "asdfghj");

    // printf("________________________________Test %ld________________________________\n", i++);
    // printf("printf:    %0*s|\n", 13, "asdfghj");
    // ft_printf("ft_printf: %0*s|\n", 13, "asdfghj");

    // printf("________________________________Test %ld________________________________\n", i++);
    // printf("printf:    %--10s|\n", "asdfghj");
    // ft_printf("ft_printf: %--10s|\n", "asdfghj");

    // printf("________________________________Test %ld________________________________\n", i++);
    // printf("printf:    %00d|\n", 25);
    // ft_printf("ft_printf: %00d|\n", 25);

    // printf("________________________________Test %ld________________________________\n", i++);
    // printf("printf:    %..d|\n", 25);
    // ft_printf("ft_printf: %..d|\n", 25);
    return (0);
}
