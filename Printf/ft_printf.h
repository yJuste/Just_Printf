/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// Standard Libraries

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

// Structure

typedef struct s_flags
{
	int		width;
	int		space;
	int		plus;
	int		minus;
	int		hashtag;
	int		zero;
	int		precision;
	char	s_width[20];
	char	s_precision[20];
	int		count;
	int		star_ds;
}	t_flags;

typedef struct s_decimal
{
	int		len;
	int		width;
	int		spaces;
	int		precision;
	int		hex;
	int		neg;
}	t_decimal;

// ft_printf.c

int		ft_printf(const char *format, ...);
void	ft_printf_recall(va_list *args, t_flags *flags, const char **format);
void	ft_printf_arguments(va_list *args, t_flags *flags, const char **format);
void	ft_print_and_count(t_flags *flags, const char **format);

// ft_printf_2.c

void	ft_flags(va_list *args, t_flags *flags, const char **format);
void	ft_flags_args(int arg, t_flags *flags, const char **format);
void	ft_flags_next(t_flags *flags, const char **format, int i, int k);
void	ft_flags_next_2(t_flags *flags, const char **format, int i);
void	ft_flags_init(t_flags *flags, t_decimal *dml);
void	ft_flags_next_3(t_flags *flags, char *format, int i, int k);

// ft_print_percent.c

void	ft_print_percent(t_flags *flags, const char **format);
void	ft_parse_percent(t_flags *flags, int spaces);

// ft_print_c.c

void	ft_print_c(int c, t_flags *flags, const char **format);
void	ft_parse_c(int c, t_flags *flags, int spaces);

// ft_print_s.c

void	ft_print_s(char *s, t_flags *flags, const char **format);
int		ft_calculate_s(char *s, t_flags *flags, int *spaces, int *len);
void	ft_parse_s(char *s, t_flags *flags, int spaces, int len);

// ft_print_p.c

void	ft_print_p(void *p, t_flags *flags, const char **format);
void	ft_no_pointeur(t_flags *flags, const char **format, int *spaces);
void	ft_p_to_hex(unsigned long int ptr, char *hexa);
int		ft_calculate_p(t_flags *flags, int *spaces, int len);
void	ft_parse_p(char *hexa, t_flags *flags, int spaces, int len);

// ft_print_d.c

void	ft_print_d(int d, t_flags *flags, const char **format);
void	ft_calculate_d(long d, t_flags *flags, t_decimal *dml);
void	ft_flags_precision_and_null_d(long d, t_flags *flags, t_decimal *dml);
void	ft_flags_next_zero_d(long *d, t_flags *flags, t_decimal *dml);
void	ft_is_negative_d(long *d, t_flags *flags, t_decimal *dml);

// ft_print_d_next.c

void	ft_parse_d(long d, t_flags *flags, t_decimal *dml);
void	ft_flags_minus_d(long d, t_flags *flags, t_decimal *dml);
void	ft_parse_next_d(long d, t_flags *flags, t_decimal *dml);
void	ft_parse_next_2_d(long *d, t_flags *flags, t_decimal *dml);
void	ft_flags_space_and_plus_d(long d, t_flags *flags, t_decimal *dml);

// ft_print_u.c

void	ft_print_u(unsigned int u, t_flags *flags, const char **format);
void	ft_calculate_u( unsigned int u, t_flags *flags, t_decimal *dml);
void	ft_flags_hashtag_u(unsigned int u, t_flags *flags, t_decimal *dml);
void	ft_flags_precision_and_null_u(unsigned int u,
		t_flags *flags, t_decimal *dml);

// ft_print_u_next.c

void	ft_parse_u(unsigned int u, t_flags *flags, t_decimal *dml);
void	ft_flags_minus_u(unsigned int u, t_flags *flags, t_decimal *dml);
void	ft_parse_next_u(unsigned int u, t_flags *flags, t_decimal *dml);
void	ft_flags_next_zero_u(unsigned int u, t_flags *flags, t_decimal *dml);
void	ft_parse_next_2_u(unsigned int u, t_flags *flags, t_decimal *dml);

// ft_printf_lib.c

int		ft_intlen(long n);
int		ft_uintlen(unsigned int n);
int		ft_uintlen_hexa(unsigned int n);
int		ft_min(int a, int b);
size_t	ft_strlen(const char *s);

// ft_printf_lib_2.c

int		ft_atoi(char *str);
void	ft_putnbr(long nbr);
void	ft_putnbr_uint(unsigned int nbr);
void	ft_putnbr_hexa(unsigned int nbr, char format);
void	ft_swap_extra(char *a, char *b);

// ft_printf_lib_3.c

void	ft_itoa_stack(int src, char *dest);
void	ft_strdup_stack(char *src, char *dest);

#endif
