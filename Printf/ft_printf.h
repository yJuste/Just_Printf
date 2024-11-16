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
}	t_flags;

// ft_printf.c

int		ft_printf(const char *format, ...);
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
int		ft_calculate_p(t_flags *flags, int *spaces, int len);
void	ft_parse_p(char *hexa, t_flags *flags, int spaces, int len);
void	ft_no_pointeur(t_flags *flags, const char **format, int *spaces);
void	ft_p_to_hex(unsigned long int ptr, char *hexa);

// ft_printf_lib.c

void	ft_putstr(char *str);
size_t	ft_strlen(const char *s);
int		ft_min(int a, int b);
void	ft_swap(char *a, char *b);

// ft_printf_lib_2.c

int		ft_atoi(char *str);

#endif
