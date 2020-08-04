#include <stdio.h>
#include "ft_printf.h"

int main()
{
    printf("%-7.5s|\n", "yolo");
    ft_printf("%-7.5s|\n", "yolo");
    
    printf("%7.7s%7.7s|\n", "hello", "world");
    ft_printf("%7.7s%7.7s|\n", "hello", "world");

    printf("%3.7s%7.7s|\n", "hello", "world");
    ft_printf("%3.7s%7.7s|\n", "hello", "world");

    printf("%7.7s%3.7s|\n", "hello", "world");
    ft_printf("%7.7s%3.7s|\n", "hello", "world");
    
    printf("%3.7s%3.7s|\n", "hello", "world");
    ft_printf("%3.7s%3.7s|\n", "hello", "world");

    printf("%32s\n", "abc");
    ft_printf("%32s\n", "abc");

    // printf("hello, %s.\n", NULL);
    // ft_printf("hello, %s.\n", NULL);

    // printf("%32s\n", NULL);
    // ft_printf("%32s\n", NULL);

    // printf("%-32s|\n", NULL);
    // ft_printf("%-32s|\n", NULL);

    // printf("%-16s|\n", NULL);
    // ft_printf("%-16s|\n", NULL);

    // printf("%.9s\n", "NULL");
    // ft_printf("%.9s\n", "NULL");

    // printf("%.09s|\n", NULL);
    // ft_printf("%.09s|\n", NULL);

    // printf("%-3.s|\n", NULL);
    // ft_printf("%-3.s|\n", NULL);

    // printf("%-3.5s|\n", NULL);
    // ft_printf("%-3.5s|\n", NULL);

    // printf("%7.6s|\n", NULL);
    // ft_printf("%7.6s|\n", NULL);

    // printf("%-3.8s|\n", NULL);
    // ft_printf("%-3.8s|\n", NULL);

    // printf("%-10.6s|\n", NULL);
    // ft_printf("%-10.6s|\n", NULL);

    // printf("%5p|\n", 0);
    // ft_printf("%5p|\n", 0);

    // printf("%.0s|\n", "NULL");
    // ft_printf("%.0s|\n", "NULL");

    printf("%2.s|\n", "asdfg");
    ft_printf("%2.s|\n", "asdfg");

    // printf("%3.3s%3.3s\n", "hello", "world");
    // ft_printf("%3.3s%3.3s\n", "hello", "world");

    // printf("%20.6s|\n", NULL);
    // ft_printf("%20.6s|\n", NULL);

    // printf("%-10.8s|\n", NULL);
    // ft_printf("%-10.8s|\n", NULL);

    // printf("%3.6s|\n", NULL);
    // ft_printf("%3.6s|\n", NULL);
    // printf("%.6d\n", -3);
    // ft_printf("%.6d\n", -3);

    // printf("%-10s|\n", NULL);
    // ft_printf("%-10s|\n", NULL);

    // printf("%.5d\n", 2);
    // ft_printf("%.5d\n", 2);

    // printf("%07d\n", -54);
    // ft_printf("%07d\n", -54);

    // printf("%8.5d|\n", 34);
    // ft_printf("%8.5d|\n", 34);

    // printf("%04d|\n", -532);
    // ft_printf("%04d|\n", -532);

    // printf("%10.5d|\n", -216);
    // ft_printf("%10.5d|\n", -216);

    // printf("this %d number\n", -267);
    // ft_printf("this %d number\n", -267);

    // printf("%8.3d|\n", -8473);
    // ft_printf("%8.3d|\n", -8473);

    printf("%-5c|\n", '\0');
    ft_printf("%-5c|\n", '\0');

    printf("%3.6s|\n", "\0");
    ft_printf("%3.6s|\n", "\0");

    printf("%8.3d\n", -8473);
    ft_printf("%8.3d\n", -8473);

    printf("%3.7d\n", 3267);
    ft_printf("%3.7d\n", 3267);

    printf("%-8.5d|\n", 34);
    ft_printf("%-8.5d|\n", 34);

    printf("%-8.5d|\n", 0);
    ft_printf("%-8.5d|\n", 0);

    printf("%8.5d|\n", 34);
    ft_printf("%8.5d|\n", 34);

    printf("%10.5d|\n", -216);
    ft_printf("%10.5d|\n", -216);

    printf("%8.3d|\n", 8375);
    ft_printf("%8.3d|\n", 8375);

    printf("%-10.5d|\n", -216);
    ft_printf("%-10.5d|\n", -216);

    printf("%5.d|\n", 0);
    ft_printf("%5.d|\n", 0);

    printf("%8.3u|\n", 8375);
    ft_printf("%8.3u|\n", 8375);

    printf("this is %x number\n", 0);
    ft_printf("this is %x number\n", 0);

    printf("%8.3x|\n", 8375);
    ft_printf("%8.3x|\n", 8375);

    printf("___________Test 21___________\n");
    printf("%-*s|\n", -32, "hello");
    ft_printf("%-*s|\n", -32, "hello");

    printf("___________Test 22___________\n");
    printf("%.*s|\n", -3, "hello");
    ft_printf("%.*s|\n", -3, "hello");

    printf("___________Test 23___________\n");
    printf("%-*.*s|\n", -7, -3, "yolooo");
    ft_printf("%-*.*s|\n", -7, -3, "yolooo");

    printf("___________Test 24___________\n");
    printf("%c|\n", 0);
    ft_printf("%c|\n", 0);

    printf("___________Test 25___________\n");
    printf("%u\n", 1001);
    ft_printf("%u\n", 1001);

    printf("___________Test 26___________\n");
    printf("%7.5s|\n", "yolo");
    ft_printf("%7.5s|\n", "yolo");

    static unsigned int		mx_u = 235;
    static char				mx_c = 'G';
    static char			   *mx_s = "Hello, neighbour!";
    static int				mx_i = 42;
    
    printf("  %u    %c    %X    %x    %p    %s  |\n", mx_u, mx_c, mx_u, mx_u, &mx_i, mx_s);
    ft_printf("  %u    %c    %X    %x    %p    %s  |\n", mx_u, mx_c, mx_u, mx_u, &mx_i, mx_s);

    printf("  %%    %u    %p    %i    %X    %c  |\n",mx_u, &mx_i, mx_i, mx_u, mx_c);
    ft_printf("  %%    %u    %p    %i    %X    %c  |\n",mx_u, &mx_i, mx_i, mx_u, mx_c);

    printf("  %%    %u    %c    %s    %i    %x  |\n", mx_u, mx_c, mx_s, mx_i, mx_u);
    ft_printf("  %%    %u    %c    %s    %i    %x  |\n", mx_u, mx_c, mx_s, mx_i, mx_u);

    printf("  %x    %s    %u    %i    %c    %X  |\n",mx_u, mx_s, mx_u, mx_i, mx_c, mx_u);
    ft_printf("  %x    %s    %u    %i    %c    %X  |\n",mx_u, mx_s, mx_u, mx_i, mx_c, mx_u);
    
    printf("  %u    %p    %c    %X    %s    %p  |\n", mx_u, &mx_i, mx_c, mx_u, mx_s, &mx_i);
    ft_printf("  %u    %p    %c    %X    %s    %p  |\n", mx_u, &mx_i, mx_c, mx_u, mx_s, &mx_i);

    printf("  %u    %s    %x    %p    %i    %c  |\n",mx_u, mx_s, mx_u, &mx_i, mx_i, mx_c);
    ft_printf("  %u    %s    %x    %p    %i    %c  |\n",mx_u, mx_s, mx_u, &mx_i, mx_i, mx_c);

    printf("  %u    %p    %X    %c    %%    %x  |\n",mx_u, &mx_i, mx_u, mx_c, mx_u);
    ft_printf("  %u    %p    %X    %c    %%    %x  |\n",mx_u, &mx_i, mx_u, mx_c, mx_u);

    printf("  %u    %i    %p    %x    %s    %X  |\n",mx_u, mx_i, &mx_i, mx_u, mx_s, mx_u);
    ft_printf("  %u    %i    %p    %x    %s    %X  |\n",mx_u, mx_i, &mx_i, mx_u, mx_s, mx_u);
    return (0);
}
