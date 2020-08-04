#include "ft_printf.h"
#include <stdio.h>

int main()
{
    size_t i;

    i = 0;
    printf("________________________________Test %ld________________________________\n", i++);
    printf("printf:    %d|\n", 123456);
    ft_printf("ft_printf: %d|\n", 123456);

    printf("________________________________Test %ld________________________________\n", i++);
    printf("printf:    %6d|\n", 123456);
    ft_printf("ft_printf: %6d|\n", 123456);

    printf("________________________________Test %ld________________________________\n", i++);
    printf("printf:    %16d|\n", 123456);
    ft_printf("ft_printf: %16d|\n", 123456);

    printf("________________________________Test %ld________________________________\n", i++);
    printf("printf:    %3s|\n", "asdf");
    ft_printf("ft_printf: %3s|\n", "asdf");

    printf("________________________________Test %ld________________________________\n", i++);
    printf("printf:    %4s|\n", "asdf");
    ft_printf("ft_printf: %4s|\n", "asdf");

    printf("________________________________Test %ld________________________________\n", i++);
    printf("printf:    %10s|\n", "asdf");
    ft_printf("ft_printf: %10s|\n", "asdf");

    printf("________________________________Test %ld________________________________\n", i++);
    printf("printf:    %10x|\n", 123456);
    ft_printf("ft_printf: %10x|\n", 123456);

    printf("________________________________Test %ld________________________________\n", i++);
    printf("printf:    %10X|\n", 123456);
    ft_printf("ft_printf: %10X|\n", 123456);

    printf("________________________________Test %ld________________________________\n", i++);
    printf("printf:    %010d|\n", 123456);
    ft_printf("ft_printf: %010d|\n", 123456);
    
    printf("________________________________Test %ld________________________________\n", i++);
    printf("printf:    %03d|\n", 123456);
    ft_printf("ft_printf: %03d|\n", 123456);

    printf("________________________________Test %ld________________________________\n", i++);
    printf("printf:    %06d|\n", 123456);
    ft_printf("ft_printf: %06d|\n", 123456);

    printf("________________________________Test %ld________________________________\n", i++);
    printf("printf:    %06u|\n", -567);
    ft_printf("ft_printf: %06u|\n", -567);

    printf("________________________________Test %ld________________________________\n", i++);
    printf("printf:    %06u|\n", 567);
    ft_printf("ft_printf: %06u|\n", 567);

    printf("________________________________Test %ld________________________________\n", i++);
    printf("printf:    %.20s|\n", "asdfghjklmnopppp");
    ft_printf("ft_printf: %.20s|\n", "asdfghjklmnopppp");

    printf("________________________________Test %ld________________________________\n", i++);
    printf("printf:    %.3s|\n", "123456");
    ft_printf("ft_printf: %.3s|\n", "123456");

    printf("________________________________Test %ld________________________________\n", i++);
    printf("printf:    %.6s|\n", "123456");
    ft_printf("ft_printf: %.6s|\n", "123456");

    printf("________________________________Test %ld________________________________\n", i++);
    printf("printf:    %.0s|\n", "123456");
    ft_printf("ft_printf: %.0s|\n", "123456");

    printf("________________________________Test %ld________________________________\n", i++);
    printf("printf:    %.5d|\n", 23);
    ft_printf("ft_printf: %.5d|\n", 23);

    printf("________________________________Test %ld________________________________\n", i++);
    printf("printf:    %.0X|\n", 23);
    ft_printf("ft_printf: %.0X|\n", 23);

    printf("________________________________Test %ld________________________________\n", i++);
    printf("printf:    %*d|\n", 10, 123456);
    ft_printf("ft_printf: %*d|\n", 10, 123456);

    printf("________________________________Test %ld________________________________\n", i++);
    printf("printf:    %*d|\n", 3, 123456);
    ft_printf("ft_printf: %*d|\n", 3, 123456);

    printf("________________________________Test %ld________________________________\n", i++);
    printf("printf:    %*d|\n", 6, 123456);
    ft_printf("ft_printf: %*d|\n", 6, 123456);

    return (0);
}
