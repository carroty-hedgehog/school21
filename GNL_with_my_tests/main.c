#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main()
{
    int     fd;
    char    *line;
    int     get;


    printf("\n BUF SIZE = %d\n", BUFFER_SIZE);

        ////////////////
        // buff = line //
        ////////////////
     printf("%s\n","======line=5======");
    // printf("BUF SIZE = %d\n", BUFFER_SIZE);
    fd = open("test1.txt", O_RDONLY);
    while ((get = get_next_line(fd, &line)) > 0)
    {
        printf("> %d < %s\n", get, line);
        free(line);
    }
    if (get < 0)
    {
        printf("Error while reading file\n");
        printf("> %d <\n", get);
    }
        
    else if (get == 0)
    {
        printf("> %d < %s\n", get, line);
        free(line);
    }
    close(fd);


         ////////////
        // fd = 42 //
        ////////////
    printf("%s\n","======FD=42======");
    // printf("BUF SIZE = %d\n", BUFFER_SIZE);
    fd = open("test3.txt", O_RDONLY);
    while ((get = get_next_line(42, &line)) > 0)
     {
        printf("> %d < %s\n", get, line);
        free(line);
    }
    if (get < 0)
    {
        printf("Error while reading file\n");
        printf("> %d <\n", get);
    }
        
    else if (get == 0)
    {
        printf("> %d < %s\n", get, line);
        free(line);
    }
    close(fd);

         ////////////
        // fd = 0 //
        ////////////
    printf("%s\n","======FD=0======");
    // printf("BUF SIZE = %d\n", BUFFER_SIZE);
    fd = open("test3.txt", O_RDONLY);
    while ((get = get_next_line(42, &line)) > 0)
    {
        printf("> %d < %s\n", get, line);
        free(line);
    }
    if (get < 0)
    {
        printf("Error while reading file\n");
        printf("> %d <\n", get);
    }
        
    else if (get == 0)
    {
        printf("> %d < %s\n", get, line);
        free(line);
    }
    close(fd);

        ///////////////
        // fail read //
        //////////////
    printf("%s\n","======FAIL_READ======");
    // printf("BUF SIZE = %d\n", BUFFER_SIZE);
    fd = open("test3.txt", O_RDONLY);
    while ((get = get_next_line(-4, &line)) > 0)
    {
        printf("> %d < %s\n", get, line);
        free(line);
    }
    if (get < 0)
    {
        printf("Error while reading file\n");
        printf("> %d <\n", get);
    }
        
    else if (get == 0)
    {
        printf("> %d < %s\n", get, line);
        free(line);
    }
    close(fd);



        ///////////////
        // long line //
        //////////////
     printf("%s\n","======long_line======");
    // printf("BUF SIZE = %d\n", BUFFER_SIZE);
    fd = open("test6.txt", O_RDONLY);
    while ((get = get_next_line(fd, &line)) > 0)
    {
        printf("> %d < %s\n", get, line);
        free(line);
    }
    if (get < 0)
    {
        printf("Error while reading file\n");
        printf("> %d <\n", get);
    }
        
    else if (get == 0)
    {
        printf("> %d < %s\n", get, line);
        free(line);
    }
    close(fd);


        /////////////
        // line = 3//
        /////////////
     printf("%s\n","======line-3======");
    // printf("BUF SIZE = %d\n", BUFFER_SIZE);
    fd = open("test7.txt", O_RDONLY);
    while ((get = get_next_line(fd, &line)) > 0)
    {
        printf("> %d < %s\n", get, line);
        free(line);
    }
    if (get < 0)
    {
        printf("Error while reading file\n");
        printf("> %d <\n", get);
    }
    else if (get == 0)
    {
        printf("> %d < %s\n", get, line);
        free(line);
    }
    close(fd);

        /////////////
        // line = 1//
        /////////////
     printf("%s\n","======line-1======");
    // printf("BUF SIZE = %d\n", BUFFER_SIZE);
    fd = open("test8.txt", O_RDONLY);
    while ((get = get_next_line(fd, &line)) > 0)
    {
        printf("> %d < %s\n", get, line);
        free(line);
    }
    if (get < 0)
    {
        printf("Error while reading file\n");
        printf("> %d <\n", get);
    }
    else if (get == 0)
    {
        printf("> %d < %s\n", get, line);
        free(line);
    }
    close(fd);

        /////////////
        // line = 0//
        /////////////
     printf("%s\n","======line-0======");
    // printf("BUF SIZE = %d\n", BUFFER_SIZE);
    fd = open("test9.txt", O_RDONLY);
    while ((get = get_next_line(fd, &line)) > 0)
    {
        printf("> %d < %s\n", get, line);
        free(line);
    }
    if (get < 0)
    {
        printf("Error while reading file\n");
        printf("> %d <\n", get);
    }
    else if (get == 0)
    {
        printf("> %d < %s\n", get, line);
        free(line);
    }
    close(fd);

        /////////////////
        // 2 long line //
        ////////////////
     printf("%s\n","======two_long_line======");
    // printf("BUF SIZE = %d\n", BUFFER_SIZE);
    fd = open("test10.txt", O_RDONLY);
    while ((get = get_next_line(fd, &line)) > 0)
    {
        printf("> %d < %s\n", get, line);
        free(line);
    }
    if (get < 0)
    {
        printf("Error while reading file\n");
        printf("> %d <\n", get);
    }
        
    else if (get == 0)
    {
        printf("> %d < %s\n", get, line);
        free(line);
    }
    close(fd);


        ///////////////
        // 2 line = 3//
        //////////////
     printf("%s\n","======two_line-3======");
    // printf("BUF SIZE = %d\n", BUFFER_SIZE);
    fd = open("test11.txt", O_RDONLY);
    while ((get = get_next_line(fd, &line)) > 0)
    {
        printf("> %d < %s\n", get, line);
        free(line);
    }
    if (get < 0)
    {
        printf("Error while reading file\n");
        printf("> %d <\n", get);
    }
    else if (get == 0)
    {
        printf("> %d < %s\n", get, line);
        free(line);
    }
    close(fd);

        ///////////////
        // 2 line = 1//
        ///////////////
     printf("%s\n","======two_line-1======");
    // printf("BUF SIZE = %d\n", BUFFER_SIZE);
    fd = open("test12.txt", O_RDONLY);
    while ((get = get_next_line(fd, &line)) > 0)
    {
        printf("> %d < %s\n", get, line);
        free(line);
    }
    if (get < 0)
    {
        printf("Error while reading file\n");
        printf("> %d <\n", get);
    }
    else if (get == 0)
    {
        printf("> %d < %s\n", get, line);
        free(line);
    }
    close(fd);

        /////////////
        //2 line = 0//
        /////////////
     printf("%s\n","======two_line-0======");
    // printf("BUF SIZE = %d\n", BUFFER_SIZE);
    fd = open("test13.txt", O_RDONLY);
    while ((get = get_next_line(fd, &line)) > 0)
    {
        printf("> %d < %s\n", get, line);
        free(line);
    }
    if (get < 0)
    {
        printf("Error while reading file\n");
        printf("> %d <\n", get);
    }
    else if (get == 0)
    {
        printf("> %d < %s\n", get, line);
        free(line);
    }
    close(fd);

        ////////////
        // stdin //
        //////////
     printf("%s\n","======stdin======");
    // printf("BUF SIZE = %d\n", BUFFER_SIZE);
    while ((get = get_next_line(0, &line)) > 0)
     {
        printf("> %d < %s\n", get, line);
        free(line);
    }
    if (get < 0)
    {
        printf("Error while reading file\n");
        printf("> %d <\n", get);
    }
    else if (get == 0)
    {
        printf("> %d < %s\n", get, line);
        free(line);
    }
    close(fd);


        ////////////
        // BONUS //
        //////////
    printf("%s\n","======bonus======");
    int fd2;
    int fd1;


    fd2 =  open("test2.txt", O_RDONLY);
    fd1 =  open("test4.txt", O_RDONLY);
    fd =  open("test5.txt", O_RDONLY);

   if ((get = get_next_line(fd, &line)) > 0)
		printf("> %d < %s\n", get, line);
	free(line);
	
	if ((get = get_next_line(fd2, &line)) > 0)
		printf("> %d < %s\n", get, line);
	free(line);
	
	if ((get = get_next_line(fd2, &line)) > 0)
		printf("> %d < %s\n", get, line);
	free(line);
	
	if ((get = get_next_line(fd, &line)) > 0)
		printf("> %d < %s\n", get, line);
	free(line);
	
	if ((get = get_next_line(fd2, &line)) > 0)
		printf("> %d < %s\n", get, line);
	free(line);
	
	if ((get = get_next_line(fd, &line)) > 0)
		printf("> %d < %s\n", get, line);
	free(line);

    if ((get = get_next_line(fd1, &line)) > 0)
		printf("> %d < %s\n", get, line);
	free(line);

    if ((get = get_next_line(fd1, &line)) > 0)
		printf("> %d < %s\n", get, line);
	free(line);
    
    if ((get = get_next_line(fd2, &line)) > 0)
		printf("> %d < %s\n", get, line);
	free(line);
	
	if ((get = get_next_line(fd, &line)) > 0)
		printf("> %d < %s\n", get, line);
	free(line);

    if ((get = get_next_line(fd1, &line)) > 0)
		printf("> %d < %s\n", get, line);
	free(line);
    

    if (get == -1)
    {
        printf("Error while reading file\n");
        printf("> %d <\n", get);
    }
    else if (get == 0)
    {
        printf("> %d < %s\n", get, line);
        free(line);
    }

    close(fd);
    close(fd1);
	close(fd2);

    return (0);
}
