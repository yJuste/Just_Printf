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
	char	s_zero[500];
	int		count;
}	t_flags;

typedef struct s_decimal
{
	int		width;
	int		spaces;
	int		len;
	int		precision;
}	t_decimal;

// ft_printf.c

int		ft_printf(const char *format, ...);
void	ft_printf_recall(t_flags *flags, const char **format);
void	ft_print_and_count(t_flags *flags, const char **format);

// ft_printf_2.c

void	ft_flags(t_flags *flags, const char **format);
void	ft_flags_next(t_flags *flags, const char **format, int i, int k);
void	ft_flags_next_2(t_flags *flags, const char **format, int i);
void	ft_flags_init(t_flags *flags);

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

// ft_print_d_next.c

void	ft_parse_d(long d, t_flags *flags, t_decimal *dml);
void	ft_flags_minus_d(long d, t_flags *flags, t_decimal *dml);
void	ft_parse_next_d(long d, t_flags *flags, t_decimal *dml);
void	ft_parse_next_2_d(long *d, t_flags *flags, t_decimal *dml);
void	ft_flags_space_and_plus_d(long d, t_flags *flags, t_decimal *dml);

// ft_printf_lib.c

int		ft_min(int a, int b);
int		ft_intlen(long n);
size_t	ft_strlen(const char *s);
void	ft_putstr(char *str);
void	ft_swap_extra(char *a, char *b);

// ft_printf_lib_2.c

int		ft_atoi(char *str);
void	ft_putnbr(long nbr);

#endif
