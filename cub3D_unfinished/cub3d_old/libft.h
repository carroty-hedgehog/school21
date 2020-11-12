/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tredtusk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 13:12:12 by tredtusk          #+#    #+#             */
/*   Updated: 2020/05/24 18:36:04 by tredtusk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

int				ft_atoi(const char *str);
int				ft_islower(int ch);
int				ft_isupper(int ch);
int				ft_isalpha(int ch);
int				ft_isdigit(int ch);
int				ft_isalnum(int ch);
int				ft_isascii(int ch);
int				ft_isprint(int ch);
int				ft_toupper(int ch);
int				ft_tolower(int ch);
int				ft_strncmp(const char *str1, const char *str2, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
char			*ft_strdup(const char *src);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strnstr(const char *big, const char *little, size_t n);
void			*ft_memset(void *s, int c, size_t n);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t count, size_t size);
void			*ft_memcpy(void *destination, const void *source, size_t n);
void			*ft_memccpy(void *destination, const void *source,
	int c, size_t n);
void			*ft_memmove(void *destination, const void *source, size_t n);
void			*ft_memchr(const void *str, int c, size_t n);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t			ft_strlcat(char *dst, const char *src, size_t n);
size_t			ft_strlen(const char *str);

char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_itoa(int n);
char			**ft_split(char const *s, char c);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_substr(char const *s, unsigned int start, size_t len);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int nb, int fd);
void			ft_putstr_fd(char const *s, int fd);

int				ft_lstsize(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(void *));
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_lstadd_front(t_list **lst, t_list *new);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
t_list			*ft_lstnew(void *content);
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void *));

#endif
