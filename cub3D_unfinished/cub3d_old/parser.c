#include <fcntl.h>
#include "libft.h"

void make_map(t_list **head, int size)
{
    char **map = ft_calloc(size + 1, sizeof(char *));
    int i = -1;
    t_list *tmp = *head;

    while (tmp)
    {
        map[++i] = tmp->content;
        tmp = tmp -> next;
    }
    i = -1;
    while(map[++i])
    {
        ft_putendl(map[i]);
    }
}

int main(int argc, char **argv)
{
    int fd = open(argv[1], O_RDONLY);
    char *line = NULL;
    t_list *head = NULL;

    while (get_next_line(fd, &line))
    {
        ft_lisadd_back(&head, ft_listnew(line));
    }
    ft_lisadd_back(&head, ft_listnew(line));
    make_map(&head, ft_listsize(head));
}