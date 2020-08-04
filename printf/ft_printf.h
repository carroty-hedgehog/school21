

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "limits.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_flag
{
	int			type;
	int			width;
	int			minus;
	int			zero;
	int			dot;
	int			err;
	int			neg;
}				t_flag;

int				ft_printf(const char *input, ...);
t_flag			ft_flag_minus(t_flag flag);
int				ft_flag_dot(const char *save,
				va_list point, t_flag *flag, int len);
t_flag			ft_flag_width(va_list point, t_flag flag);
t_flag			ft_flag_digit(const char *save, t_flag flag, int *i);
int				ft_line_work(va_list point, t_flag flag, int c);
int				ft_distribution(va_list point,
				const char *save, int i, int len);
char			*ft_itoa_hex(unsigned long long num);
int				ft_work_width_space(int width);
int				ft_work_string(char *str, t_flag flag);
int				ft_work_hex(unsigned int num, t_flag flag, int lowercase);
int				ft_work_width_zero(int width);
int				ft_work_int(t_flag flag, long long num);
int				ft_work_percent(t_flag flag);
int				ft_work_pointer(unsigned long long num, t_flag flag);
int				ft_work_unsigned(t_flag flag, unsigned int num);
int				ft_putchar(char c);
int				ft_write_char(char c, t_flag flag);
int				ft_write_string(char *str, int end);
int				ft_write_int(t_flag flag, char *num_str);
size_t			ft_strlen(const char *str);
int				ft_isdigit(int c);
int				ft_toupper(int c);
char			*ft_itoa(long long n);
char			*ft_strdup(const char *src);

#endif
